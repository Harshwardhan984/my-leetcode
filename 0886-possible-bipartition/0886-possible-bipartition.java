class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());

        for(int[] d : dislikes){
            adj.get(d[0]).add(d[1]);
            adj.get(d[1]).add(d[0]);
        }

        int[] color = new int[n + 1];

        for(int i = 1; i <= n; i++){

            if(color[i] != 0)
                continue;

            Stack<Integer> st = new Stack<>();
            st.push(i);
            color[i] = 1;

            while(!st.isEmpty()){

                int cur = st.pop();

                for(int ng : adj.get(cur)){

                    if(color[ng] == 0){
                        color[ng] = -color[cur];
                        st.push(ng);
                    }
                    else if(color[ng] == color[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
}