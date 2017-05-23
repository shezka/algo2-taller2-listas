#ifndef LISTA_H_
#define LISTA_H_
#define DEBUG
#include <string>
#include <sstream>
#include <ostream>
using namespace std;
//namespace listaaed2 {
    template<typename T>
    class Lista {
        struct Nodo {
            T    elem;
            Nodo *anterior, *siguiente;

            Nodo(const T &e, Nodo *ant, Nodo *sig) :
                    elem(e), anterior(ant), siguiente(sig) {
//                std::cout << "Creado nodo: " << this << std::endl;
            }

            ~Nodo(){
//                std::cout << "Destruyendo nodo:" << this << std::endl;
            }

        };

        Nodo *cabeza;
        int tam;

    public:
//EMPIEZA ITERADOR
        class Iterador {
            Lista<T> *lista;
            Nodo     *nodo;

            Iterador(Lista *lista, Nodo *nodo);

            friend class Lista<T>;

        public:
            bool HaySiguiente() const;

            T &Siguiente() const;

            void Avanzar();

            Iterador Insertar(const T &e);

            void Remover();
        };


        class const_Iterador {
            const Lista<T> *lista;
            const Nodo   *nodo;

            const_Iterador(const Lista *lista, const Nodo *nodo);

            friend class Lista<T>;

        public:
            bool HaySiguiente() const;

            const T& Siguiente() const;

            void Avanzar();
        };

        Lista();

        ~Lista(){
            while (cabeza != nullptr) {
                Nodo *aux = cabeza;
                cabeza = cabeza->siguiente;
                delete aux;
            }
        }

        Iterador AgregarAdelante(const T &t);

        int Longitud() const;

        Iterador CrearIt();

        const_Iterador CrearIt() const;

        int cant();

        string to_s();
    };

    template<typename T>
    Lista<T>::Lista() : cabeza(NULL), tam(0) {}

    template<typename T>
    typename Lista<T>::Iterador
    Lista<T>::AgregarAdelante(const T &e) {
        cabeza = new Nodo(e, NULL, cabeza);
        if (cabeza->siguiente != NULL)
            cabeza->siguiente->anterior = cabeza;
        if (cabeza->anterior != nullptr) cabeza->anterior->siguiente = cabeza;
        typename Lista<T>::Iterador it = this->CrearIt();
        tam++;
        return it;
    }

    template<class T>
    int Lista<T>::cant()
    {
        int i = 0;
        Lista<T>::Iterador it = CrearIt();
        while (it.HaySiguiente())
        {
            i++;
            it.Avanzar();
        }
        return i;
    }
    template<class T>
    string Lista<T>::to_s() {
        std::ostringstream os;
        os << *this;
        return os.str();
    }
template<class T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& l) {

    typename   Lista<T>::const_Iterador miIt = l.CrearIt();
    os << "[";
    while (miIt.HaySiguiente()) {
        os << miIt.Siguiente();
        miIt.Avanzar();
        if (miIt.HaySiguiente()) os << ", ";
    }
   // os << miIt.Siguiente();
    os << "]";
    return os;
    // os << std::endl;
}


    template<typename T>
    int Lista<T>::Longitud() const {
        return tam;
    }

    template<typename T>
    typename Lista<T>::const_Iterador Lista<T>::CrearIt() const {
        return const_Iterador(this, this->cabeza);
    }

    template<typename T>
    typename Lista<T>::Iterador Lista<T>::CrearIt() { return Iterador(this, this->cabeza); }

    template<typename T>
    bool Lista<T>::Iterador::HaySiguiente() const {
        return nodo != nullptr;
    }

    template<typename T>
    T &Lista<T>::Iterador::Siguiente() const {
        return nodo->elem;
    }

    template<typename T>
    void Lista<T>::Iterador::Avanzar() {
        nodo = nodo->siguiente;
    }

    template<typename T>
    typename Lista<T>::Iterador Lista<T>::Iterador::Insertar(const T &e) {
      //  this->lista->
        if (nodo != nullptr) {
            Nodo* aux = nodo;
            nodo = new Nodo(e, nodo, nodo->siguiente);
            aux->siguiente = nodo;
            if (nodo->siguiente != nullptr)  nodo->siguiente->anterior = nodo;
        } else if (nodo == nullptr)
        {
            nodo = new Nodo(e, nullptr, nullptr);
            lista->cabeza = nodo;
        }
        /*else
        {
            nodo = new Nodo(e, nodo, nodo->siguiente);
            lista->cabeza = nodo;
        }*/
        lista->tam++;
        return *this;
       // return Iterador(lista, nodo);
        //lista->tam++;
       // Lista<T>::Nodo *aux = nodo->siguiente;
        //nodo->siguiente = new Lista<T>::Nodo(e);
        //nodo->siguiente->siguiente = aux;
    }

    template<typename T>
    void Lista<T>::Iterador::Remover() {
        Nodo *aux = nodo;
        if (nodo->anterior != nullptr) nodo->anterior->siguiente = nodo->siguiente;
        if (nodo->siguiente != nullptr) nodo->siguiente->anterior = nodo->anterior;
        nodo = nodo->siguiente;
        delete aux;
    }

    template<typename T>
    Lista<T>::Iterador::Iterador(Lista<T> *lista, Lista<T>::Nodo *nodo) : lista(lista), nodo(nodo) {}

    template<typename T>
    void Lista<T>::const_Iterador::Avanzar() {
        nodo = nodo->siguiente;
    }

    template<typename T>
    bool Lista<T>::const_Iterador::HaySiguiente() const {
        return nodo != nullptr;
    }

    template<typename T>
    const T& Lista<T>::const_Iterador::Siguiente() const {
        return nodo->elem;
    }

    template<typename T>
    Lista<T>::const_Iterador::const_Iterador(const Lista<T> *lista, const Lista<T>::Nodo *nodo) : lista(lista), nodo(nodo) {}


// Ej1: implementar la función crearIt de Lista y las clases Iterador y const_Iterador
// Ej2: implementar las funciones cant y to_s usando iteradores
//}
#endif /* LISTA_H_ */