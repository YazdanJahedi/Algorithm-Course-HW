import java.util.*;

public class Main {
    static int[] p;
    static int[][] e;
    static int n, m;
    static int wgt = 0;

    public static void setup(int n) {
        wgt = 0;
        p = new int[n];
        for (int i = 0; i < n; i++) p[i] = i;
    }

    public static int search(int i) {
        if (i != p[i]) return p[i] = search(p[i]);
        return i;
    }

    public static boolean un(int u, int v) {
        int cu = search(u);
        int cv = search(v);
        if (cu != cv) {
            p[cu] = cv;
            return true;
        }
        return false;
    }

    public static List<List<Integer>> cal_PC_C() {
        List<Integer> c_edges = new ArrayList<>();
        List<Integer> pc_edges = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; i++) e[i] = new int[]{e[i][0], e[i][1], e[i][2], i};
        Arrays.sort(e, Comparator.comparingInt(a -> a[2]));
        int w = mst_w(-1, -1);
        for (int i = 0; i < m; i++)
            if (w < mst_w(i, -1))
                c_edges.add(e[i][3]);
            else if (w == mst_w(-1, i))
                pc_edges.add(e[i][3]);

        Collections.sort(c_edges);
        Collections.sort(pc_edges);
        ans.add(c_edges);
        ans.add(pc_edges);
        return ans;
    }

    public static int mst_w(int blk, int pe) {
        setup(n);
        if (pe != -1) {
            wgt += e[pe][2];
            un(e[pe][0], e[pe][1]);
        }
        for (int i = 0; i < m; i++)
            if (i != pe && i != blk)
                if (un(e[i][0], e[i][1]))
                    wgt += e[i][2];
        for (int i = 0; i < n; i++)
            if (search(i) != search(0))
                return Integer.MAX_VALUE;
        return wgt;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        e = new int[m][3];
        for (int i = 0; i < m; i++) {
            int u, v, c;
            u = scanner.nextInt();
            v = scanner.nextInt();
            c = scanner.nextInt();
            e[i][0] = u;
            e[i][1] = v;
            e[i][2] = c;
        }
        List<List<Integer>> ans = cal_PC_C();
        List<Integer> l1 = ans.get(0);
        List<Integer> l2 = ans.get(1);
        for (Integer integer : l1)
            System.out.print(integer + " ");

        System.out.println();
        for (Integer integer : l2)
            System.out.print(integer + " ");

    }
}