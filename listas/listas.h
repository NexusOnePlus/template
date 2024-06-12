#include <iostream>
#include <string.h>
using namespace std;

struct nodo
{
    char nomb[20]; // Cadena de caracteres correspondientes al nombre dentro del nodo
    nodo *sig;     // puntero nodo que apunta al siguiente nodo
};

// Funciones
void crea_i(nodo *&p);                 // crea una lista desde el inicio
void crea_f(nodo *&p);                 // crea una lista desde el final
void inserta_i(nodo *&p);              // inserta un solo unico nodo desde el inicio
void inserta_f(nodo *&p);              // inserta un solo unico nodo desde el final
void inserta_ad(nodo *&p, char *ref);  // inserta un nodo antes de una referencia
void despues_dd(nodo *&p, char *ref);  // insertar un nodo despues de una referencia
void recorre(nodo *&p);                // recorre y muestra la lista enlazada
void eliminar_p(nodo *&p);             // elimina el primer nodo de la lista
void eliminar_u(nodo *&p);             // elimina el ultimo nodo de la lista
void eliminar_x(nodo *&p, char *ref);  // elimina un nodo especifico en la lista
void eliminar_ad(nodo *&p, char *ref); // elimina un nodo antes de una referencia
void eliminar_dd(nodo *&p, char *ref); // elimina un nodo despues de una referencia
// Funcion crear lista desde el inicio
void crea_i(nodo *&p)
{
    char op;
    do
    {
        nodo *q = new (nodo);
        cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
        cout << "\n\tNOMBRE: ";
        cin >> q->nomb;
        q->sig = p;
        p = q;
        cout << "\nDESEA INSERTAR MAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
    cout << "\n[LISTA CREADA DESDE EL INICIO Y DATOS INSERTADOS]\n\n";
    recorre(p);
}

// Funcion crear lista desde el final
void crea_f(nodo *&p)
{
    char op;
    do
    {
        nodo *q = new (nodo);
        cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
        cout << "\n\tNOMBRE: ";
        cin >> q->nomb;
        q->sig = NULL;
        nodo *r = p;
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            while (r->sig != NULL)
            {
                r = r->sig;
            }
            r->sig = q;
        }
        cout << "\nDESEA INSERTAR MAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
    cout << "\n[LISTA CREADA DESDE EL FINAL Y DATOS INSERTADOS]\n\n";
    recorre(p);
}

// Funcion insertar nodo desde el inicio
void inserta_i(nodo *&p)
{
    nodo *q = new (nodo);
    cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
    cout << "\n\tNOMBRE: ";
    cin >> q->nomb;
    q->sig = p;
    p = q;
    cout << "\n[NODO INSERTADO DESDE EL INICIO]\n\n";
    recorre(p);
}

// Funcion insertar nodo desde el final
void inserta_f(nodo *&p)
{
    nodo *q = new (nodo);
    cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
    cout << "\n\tNOMBRE: ";
    cin >> q->nomb;
    q->sig = NULL;
    nodo *r = p;
    if (p != NULL)
    {
        while (r->sig != NULL)
        {
            r = r->sig;
        }
        r->sig = q;
    }
    else
    {
        p = q;
    }

    cout << "\n[NODO INSERTADO DESDE EL FINAL]\n\n";
    recorre(p);
}

// Funcion insertar un solo unico nodo antes de una referencia
void inserta_ad(nodo *&p, char *ref)
{
    if (p != NULL)
    {
        nodo *r = p;
        nodo *t;
        bool cen = false;
        while (strcmp(r->nomb, ref) && cen == false)
        {
            if (r->sig != NULL)
            {
                t = r;
                r = r->sig;
            }
            else
            {
                cen = true;
            }
        }
        if (cen == false)
        {
            nodo *q = new (nodo);
            cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
            cout << "\n\tNOMBRE: ";
            cin >> q->nomb;
            q->sig = r;
            if (p == r)
            {
                p = q;
            }
            else
            {
                t->sig = q;
            }
            cout << "\n[NODO INSERTADO ANTES DE LA REFERENCIA]\n\n";
            recorre(p);
        }
        else
        {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA\n\n";
            recorre(p);
        }
    }
    else
    {
        cout << "\nLA LISTA SE ENCUENTRA VACIA\n\n";
    }
}

// Funcion insertar un solo unico nodo despues de una referencia
void despues_dd(nodo *&p, char *ref)
{
    if (p != NULL)
    {
        nodo *r = p;
        bool cen = 0;
        while (strcmp(r->nomb, ref) != 0 && cen == false)
        {
            if (r->sig != NULL)
            {
                r = r->sig;
            }
            else
            {
                cen = true;
            }
        }
        if (cen == false)
        {
            nodo *q = new (nodo);
            cout << "\nINTRODUZCA EL NOMBRE DEL NUEVO NODO\n";
            cout << "\n\tNOMBRE: ";
            cin >> q->nomb;
            q->sig = r->sig;
            r->sig = q;
            cout << "\n[NODO INSERTADO DESPUES DE LA REFERENCIA]\n\n";
            recorre(p);
        }
        else
        {
            cout << "\nLA REFERENCIA NO SE ENCUENTRA EN LA LISTA\n\n";
            recorre(p);
        }
    }
    else
    {
        cout << "\nLA LISTA SE ENCUENTRA VACIA\n\n";
    }
}

// Funcion para mostrar la lista enlazada de nodos
void recorre(nodo *&p)
{
    if (p != NULL)
    {
        cout << "\n------------------------------" << endl;
        cout << "LISTA ENLAZADDA SIMPLE ACTUAL" << endl;
        cout << "------------------------------\n"
             << endl;
        nodo *q = p;
        while (q != NULL)
        {
            cout << '\t' << q->nomb << endl;
            q = q->sig;
        }
        cout << endl;
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}

// Funcion eliminar el primer nodo de una lista
void eliminar_p(nodo *&p)
{
    if (p != NULL)
    {
        nodo *q = p;
        p = p->sig;
        delete (q);
        cout << "\n[PRIMER NODO DE LA LISTA ELIMINADO]\n\n";
        recorre(p);
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}

// Funcion eliminar el ultimo nodo de una lista
void eliminar_u(nodo *&p)
{
    if (p != NULL)
    {
        nodo *q = p;
        if (p->sig == NULL)
        {
            p = NULL;
            delete q;
        }
        else
        {
            nodo *r;
            while (q->sig != NULL)
            {
                r = q;
                q = q->sig;
            }
            r->sig = NULL;
            delete (q);
            cout << "\n[ULTIMO NODO DE LA LISTA ELIMINADO]\n\n";
            recorre(p);
        }
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}

// Funcion eliminar un nodo por una referencia de una lista
void eliminar_x(nodo *&p, char *ref)
{
    if (p != NULL)
    {
        nodo *q = p;
        bool cen = false;
        nodo *r;
        while (strcmp(q->nomb, ref) != 0 && cen == false)
        {
            if (q->sig != NULL)
            {
                r = q;
                q = q->sig;
            }
            else
            {
                cen = true;
            }
        }

        if (cen == false)
        {
            if (q == p)
            {
                p = p->sig;
            }
            else
            {
                r->sig = q->sig;
            }
            delete (q);
            cout << "\n[NODO CON REFERENCIA DE LA LISTA ELIMINADO]\n\n";
            recorre(p);
        }
        else
        {
            cout << "\nEL NODO NO SE ENCUENTRA EN LA LISTA\n\n";
            recorre(p);
        }
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}

// Funcion eliminar un solo unico nodo antes de una referencia
void eliminar_ad(nodo *&p, char *ref)
{
    if (p != NULL)
    {
        if (strcmp(p->nomb, ref) == 0)
        {
            cout << "\nNO HAY NINGUN NODO ANTES DE LA REFERENCIA\n\n";
            recorre(p);
        }
        else
        {
            nodo *q = p;
            nodo *r = p;
            nodo *t = p;

            bool cen = false;
            while (strcmp(q->nomb, ref) != 0 && cen == false)
            {
                if (q->sig != NULL)
                {
                    t = r;
                    r = q;
                    q = q->sig;
                }
                else
                {
                    cen = true;
                }
            }

            if (cen == false)
            {
                if (p->sig == q)
                {
                    p = p->sig;
                }
                else
                {
                    t->sig = q;
                }
                delete (r);
                cout << "\n[NODO ANTERIOR A LA REFERENCIA DE LA LISTA ELIMINADO]\n\n";
                recorre(p);
            }
            else
            {
                cout << "\nEL NODO NO SE ENCUENTRA EN LA LISTA\n\n";
                recorre(p);
            }
        }
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}

// Funcion eliminar un solo unico nodo despues de una referencia
void eliminar_dd(nodo *&p, char *ref)
{
    if (p != NULL)
    {
        nodo *q = p;
        bool cen = false;
        while (strcmp(q->nomb, ref) != 0 && cen == false)
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = true;
            }
        }
        if (cen == false)
        {
            if (q->sig != NULL)
            {
                nodo *r = q->sig;
                q->sig = r->sig;
                delete (r);
                cout << "\n[NODO ANTERIOR A LA REFERENCIA DE LA LISTA ELIMINADO]\n\n";
                recorre(p);
            }
            else
            {
                cout << "\nNO HAY NINGUN NODO DESPUES DE LA REFERENCIA\n\n";
                recorre(p);
            }
        }
        else
        {
            cout << "\nEL NODO NO SE ENCUENTRA EN LA LISTA\n\n";
            recorre(p);
        }
    }
    else
    {
        cout << "\n\n LISTA VACIA\n";
    }
}