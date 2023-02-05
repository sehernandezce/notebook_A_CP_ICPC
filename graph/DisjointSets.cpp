//Algorithm or Logic: UnionFind
// Complexity : O(?)
// Saber si existen ciclos en un grafo no dirigido conexo. O conocer los componentes.
// Para conjuntos disyuntos.
struct UnionFind{
    vector<int> p, rank; // p -> Who is father? // Rank -> La altura del arbol Desde el nodo i
    //vector<int> numSon; // El padre se cuenta asimismo :v
    UnionFind(int N){
        rank.assign(N+5,0); p.assign(N+5,0); //numSon.assign(N+5,1);
        for(int i = 1; i <=N; i++) p[i] = i;
    }
    int findSet(int i) {return (p[i]==i) ? i: (p[i]=findSet(p[i]));}
    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);
            //int sumSon = numSon[x]+numSon[y]; numComp--;
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
            //numSon[findSet(i)] = sumSon;
        }
        //mxSize = max(mxSize,numSon[findSet(j)]);
    }
};
 