#include <string.h>

#include <iostream>
using namespace std;

struct nodo {
    char nomb[20];
    nodo *ant, *sig;
};

void cread_i(nodo *&, nodo *&);
void cread_f(nodo *&, nodo *&);
void recorre(nodo *);
void insertad_i(nodo *&, nodo *&);
void insertad_f(nodo *&, nodo *&);
void insertad_ad(nodo *&, char *);
void insertad_dd(nodo *&, char *);
void eliminard_p(nodo *&, nodo *&);
void eliminard_u(nodo *&, nodo *&);
void eliminard_x(nodo *&, nodo *&, char *);
void eliminard_ad(nodo *&, char *);
void eliminard_dd(nodo *&, char *);

void cread_i(nodo *&p, nodo *&f) {
    nodo *q;
    char op;
    p = NULL;
    f = NULL;
    do {
        nodo *q = new (nodo);
        cout << "\n NOMBRE: ";
        cin >> q->nomb;
        q->ant = NULL;
        q->sig = p;
        if (p == NULL) {
            f = q;
        } else {
            p->ant = q;
        }
        p = q;
        cout << "\nMAS DATOS (S/N)? :";
        cin >> op;
    } while (op == 'S' || op == 's');
    cout << "\n[LISTA CREADA POR EL INICIO]" << endl;
    recorre(p);
}

void cread_f(nodo *&p, nodo *&f) {
    nodo *q, *r;
    char op;
    p = NULL;
    f = NULL;
    do {
        nodo *q = new (nodo);
        cout << "\n NOMBRE: ";
        cin >> q->nomb;
        q->sig = NULL;
        q->ant = f;
        if (p == NULL) {
            p = q;
        } else {
            f->sig = q;
        }
        f = q;
        cout << "\nMAS DATOS (S/N)? :";
        cin >> op;
    } while (op == 'S' || op == 's');
    cout << "\n[LISTA CREADA POR EL FINAL]" << endl;
    recorre(p);
}

void recorre(nodo *p) {
    nodo *q;
    q = p;
    cout << "\n\tLISTA DE DATOS:" << endl;
    cout << "\t===============" << endl;
    while (q != NULL) {
        cout << '\t' << q->nomb << endl;
        ;
        q = q->sig;
    }
    cout << endl;
}

void insertad_i(nodo *&p, nodo *&f) {
    nodo *q = new (nodo);
    cout << "\n NOMBRE: ";
    cin >> q->nomb;
    q->sig = p;
    q->ant = NULL;
    if (p == NULL) {
        f = q;
    } else {
        p->ant = q;
    }
    p = q;
    cout << "\n[NODO INSERTADO POR EL INICIO]" << endl;
    recorre(p);
}

void insertad_f(nodo *&p, nodo *&f) {
    nodo *q = new (nodo);
    cout << "\n NOMBRE: ";
    cin >> q->nomb;
    q->sig = NULL;
    q->ant = f;
    if (p == NULL) {
        p = q;
    } else {
        f->sig = q;
    }
    f = q;
    cout << "\n[NODO INSERTADO POR EL FINAL]" << endl;
    recorre(p);
}

void insertad_ad(nodo *&p, char *ref) {
    if (p != NULL) {
        nodo *q = p;
        bool cen = false;
        while (strcmp(p->nomb, ref) != 0 && cen == false) {
            if (q->sig != NULL) {
                q = q->sig;
            } else {
                cen = true;
            }
        }
        if (cen == false) {
            nodo *x = new (nodo);
            cout << "\n NOMBRE: ";
            cin >> x->nomb;
            x->sig = q;
            nodo *r = q->ant;
            x->ant = r;
            q->ant = x;
            if (p == q) {
                p = x;
            } else {
                r->sig = x;
            }
            cout << "\n[NODO INSERTADO ANTES DE LA REFERENCIA]" << endl;
            recorre(p);
        } else {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA" << endl;
        }
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void insertad_dd(nodo *&f, char *ref) {
    if (f != NULL) {
        nodo *q = f;
        bool cen = false;
        while (strcmp(q->nomb, ref) != 0 && cen == false) {
            if (q->ant != NULL) {
                q = q->ant;
            } else {
                cen = true;
            }
        }
        if (cen == false) {
            nodo *x = new (nodo);
            cout << "\n NOMBRE : ";
            cin >> x->nomb;
            x->ant = q;
            nodo *r = q->sig;
            x->sig = r;
            q->sig = x;
            if (f == q) {
                f = x;
            } else {
                r->ant = x;
            }
            cout << "\n[NODO INSERTADO DESPUES DE UNA REFERENCIA]" << endl;
        } else {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA" << endl;
        }
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void eliminard_p(nodo *&p, nodo *&f) {
    if (p != NULL) {
        nodo *q = p;
        p = p->sig;
        if (q == f) {
            f = NULL;
        } else {
            p->ant = NULL;
        }

        delete (q);
        cout << "\n[PRIMER NODO DE LA LISTA ELIMINADO]" << endl;
        recorre(p);
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void eliminard_u(nodo *&p, nodo *&f) {
    if (p != NULL) {
        nodo *q = f;
        f = f->ant;
        if (q == p) {
            p = NULL;
        } else {
            f->sig = NULL;
        }
        delete (q);
        cout << "\n[ULTIMO NODO DE LA LISTA ELIMINADA]" << endl;
        recorre(p);
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void eliminard_x(nodo *&p, nodo *&f, char *x) {
    if (p != NULL) {
        nodo *q = p;
        bool cen = false;
        while (strcmp(q->nomb, x) != 0 && cen == false) {
            if (q->sig != NULL) {
                q = q->sig;
            } else {
                cen = true;
            }
        }
        if (cen == false) {
            if (p == f) {
                p = NULL;
                f = NULL;
            } else {
                if(p == q){
                    p = p->sig;
                    p->ant = NULL;
                } else {
                    if(q == f){
                        f = f->ant;
                        f->sig = NULL;
                    } else {
                        nodo *r = q->ant;
                        nodo *s = q->sig;
                        r->sig = s;
                        s->ant = r;
                    }
                }
            }
            delete (q);
            cout << "\n[NODO ESPECIFICO DE LA LISTA ELIMINADA]" << endl;
            recorre(p);
        } else {
            cout << "\n EL NODO NO SE ENCUENTRA EN LA LISTA" << endl;
        }
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void eliminard_ad(nodo *&p, char *ref) {
    if(p != NULL) {
        nodo *q = p;
        bool cen = false;
        while (strcmp(q->nomb, ref) != 0 && cen == false)
        {   
            if(q->sig !=NULL){
                q = q->sig;
            } else {
                cen = true;
            }
        }
        if (cen == false){
            if(p == q){
                cout << "\nNO HAY NODO ANTES DE LA REFERENCIA" << endl;
            } else {
                nodo *r = q->ant;
                if(p == r) {
                    p = p->sig;
                } else {
                    nodo *s = r->ant;
                    s->sig = q;
                    q->ant = s;
                }
                cout << "\n[NODO ANTES DE UNA REFERENCIA ELIMINADO]" << endl;
                delete (r);
                recorre(p);
            }
        } else {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA" << endl;
        }
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}

void eliminard_dd(nodo *&f, char *ref) {
    if(f != NULL) {
        nodo *q = f;
        bool cen = false;
        while (strcmp(q->nomb, ref) != 0 && cen == false){
            if(q->ant != NULL){
                q = q->ant;
            } else {
                cen = true;
            }
        }

        if(cen == false){
            if(f == q){
                cout << "\nNO HAY NODO DESPUES DE LA REFERENCIA" << endl;
            } else {
                nodo *r = q->sig;
                nodo *s = r->sig;
                if(r == f){
                    f=q;
                    f->sig = NULL;
                } else {
                    s->ant = q;
                }
                delete (r);
                cout << "\n[NODO DESPUES DE UNA REFERENCIA ELIMINADO]" << endl;
            }
        } else {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA" << endl; 
        }
    } else {
        cout << "\nLA LISTA SE ENCUENTRA VACIA" << endl;
    }
}
