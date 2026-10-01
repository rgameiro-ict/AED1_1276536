/* ALGORITMOS DE LISTAS, ÁRVORES, GRAFOS, BUSCAS E ORDENAÇÕES PADRÕES PARA CONSULTA  */

// QUICK SORT
int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++){
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

// MERGE SORT
void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r){
        if (v[i] <= v[j]){
            w[k++] = v[i++];
        }
        else{
            w[k++] = v[j++];
        }
    }
    while (i < q){
        w[k++] = v[i++];
    }
    while (j < r){
        w[k++] = v[j++];
    }
    for (i = p; i < r; i++){
        v[i] = w[i-p];
    }
    free (w);
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
    }
}

// PILHAS

