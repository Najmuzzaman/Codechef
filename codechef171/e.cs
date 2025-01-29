using System;
using System.Collections.Generic;

class Program
{
    const int MOD = 1000000007;
    const int MAX_X = 200000;
    const int MAX_POW = 200030;
    static int[] grundy = new int[MAX_X + 1];
    static long[] pow2 = new long[MAX_POW + 1];

    class SegmentTreeNode
    {
        public int L, R;
        public SegmentTreeNode Left, Right;
        public int[] Basis = new int[30];
        public int Count;

        public SegmentTreeNode(int l, int r)
        {
            L = l;
            R = r;
            Count = 0;
        }

        public void UpdateFromValue(int val)
        {
            Array.Clear(Basis, 0, Basis.Length);
            int tmp = val;
            for (int i = 29; i >= 0; i--)
            {
                if ((tmp & (1 << i)) != 0)
                {
                    if (Basis[i] == 0)
                    {
                        Basis[i] = tmp;
                        break;
                    }
                    else
                    {
                        tmp ^= Basis[i];
                    }
                }
                if (tmp == 0) break;
            }
            Count = 1;
        }

        public void MergeChildren()
        {
            if (Left == null || Right == null) return;

            Array.Copy(Left.Basis, Basis, 30);
            foreach (int x in Right.Basis)
            {
                if (x != 0)
                {
                    int tmp = x;
                    for (int j = 29; j >= 0; j--)
                    {
                        if ((tmp & (1 << j)) != 0)
                        {
                            if (Basis[j] == 0)
                            {
                                Basis[j] = tmp;
                                break;
                            }
                            else
                            {
                                tmp ^= Basis[j];
                            }
                        }
                        if (tmp == 0) break;
                    }
                }
            }
            Count = Left.Count + Right.Count;
        }
    }

    static SegmentTreeNode Build(int l, int r, int[] arr)
    {
        SegmentTreeNode node = new SegmentTreeNode(l, r);
        if (l == r)
        {
            node.UpdateFromValue(arr[l - 1]);
        }
        else
        {
            int mid = (l + r) / 2;
            node.Left = Build(l, mid, arr);
            node.Right = Build(mid + 1, r, arr);
            node.MergeChildren();
        }
        return node;
    }

    static void Update(SegmentTreeNode node, int idx, int val)
    {
        if (node.L == node.R && node.L == idx)
        {
            node.UpdateFromValue(val);
            return;
        }

        if (idx <= node.Left.R)
            Update(node.Left, idx, val);
        else
            Update(node.Right, idx, val);

        node.MergeChildren();
    }

    static int[] currentBasis = new int[30];
    static int currentCount = 0;

    static void Query(SegmentTreeNode node, int l, int r)
    {
        if (node.R < l || node.L > r)
            return;

        if (l <= node.L && node.R <= r)
        {
            currentCount += node.Count;
            foreach (int x in node.Basis)
            {
                if (x != 0)
                {
                    int tmp = x;
                    for (int j = 29; j >= 0; j--)
                    {
                        if ((tmp & (1 << j)) != 0)
                        {
                            if (currentBasis[j] == 0)
                            {
                                currentBasis[j] = tmp;
                                break;
                            }
                            else
                            {
                                tmp ^= currentBasis[j];
                            }
                        }
                        if (tmp == 0) break;
                    }
                }
            }
            return;
        }

        Query(node.Left, l, r);
        Query(node.Right, l, r);
    }

    static void Precompute()
    {
        for (int x = 1; x <= MAX_X; x++)
        {
            HashSet<int> digits = new HashSet<int>();
            int tmp = x;
            while (tmp > 0)
            {
                int d = tmp % 10;
                if (d != 0)
                    digits.Add(d);
                tmp /= 10;
            }

            HashSet<int> s = new HashSet<int>();
            foreach (int d in digits)
            {
                if (x >= d)
                    s.Add(grundy[x - d]);
            }

            int mex = 0;
            while (s.Contains(mex))
                mex++;

            grundy[x] = mex;
        }

        pow2[0] = 1;
        for (int i = 1; i <= MAX_POW; i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
    }

    static void Main()
    {
        Precompute();
        int N = int.Parse(Console.ReadLine());
        int[] A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int[] grundyA = new int[N];
        for (int i = 0; i < N; i++)
            grundyA[i] = grundy[A[i]];

        SegmentTreeNode root = Build(1, N, grundyA);

        int Q = int.Parse(Console.ReadLine());
        for (int i = 0; i < Q; i++)
        {
            string[] parts = Console.ReadLine().Split();
            if (parts.Length == 0) continue;

            if (parts[0] == "1")
            {
                int L = int.Parse(parts[1]);
                int R = int.Parse(parts[2]);
                Array.Clear(currentBasis, 0, currentBasis.Length);
                currentCount = 0;
                Query(root, L, R);

                int t = R - L + 1;
                int r = 0;
                foreach (int x in currentBasis)
                    if (x != 0) r++;

                long ans = (pow2[t] - pow2[t - r] + MOD) % MOD;
                Console.WriteLine(ans);
            }
            else
            {
                int i1 = int.Parse(parts[1]);
                int x = int.Parse(parts[2]);
                int newG = grundy[x];
                Update(root, i1, newG);
            }
        }
    }
}