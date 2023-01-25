/*
    JOSÉ CARLOS CORTÉS HERNÁNDEZ. 212591438
    Actividad 1. Repaso de programación
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Paquete
{
public:
    int id;
    string origen;
    string destino;
    float peso;
    Paquete *siguiente;
    Paquete(); //Constructor
    ~Paquete(); //Destructor
};

Paquete::Paquete()
{
    id = -1;
    origen = "";
    destino = "";
    peso = 0.0;
    siguiente = NULL;
}

Paquete::~Paquete()
{

}

class Paqueteria
{
public:
    Paquete *inicio;
    Paqueteria();
    bool vacia();
    void agregar(int newId, string newOrigen, string newDestino, float newPeso);
    void eliminar();
    void mostrar();
    void guardar();
    void recuperar();
};

Paqueteria::Paqueteria()
{
    inicio = NULL;
}

bool Paqueteria::vacia()
{
    if(inicio == NULL)
    {
        return true;
    }
    return false;
}

void Paqueteria::agregar(int newId, string newOrigen, string newDestino, float newPeso)
{
    Paquete *temp = new Paquete;
    temp->id = newId;
    temp->origen = newOrigen;
    temp->destino = newDestino;
    temp->peso = newPeso;
    if(vacia())
    {
        inicio = temp;
    }
    else
    {
        temp->siguiente = inicio;
        inicio = temp;
    }
}

void Paqueteria::eliminar(){
    if(vacia())
    {
        cout << "\tNo hay paquetes" << endl;
    }
    else
    {
        cout << "\tPAQUETE A ELIMINAR" << endl;
        cout << "\tId: " << inicio->id << endl;
        cout << "\tOrigen: " << inicio->origen << endl;
        cout << "\tDestino: " << inicio->destino << endl;
        cout << "\tPeso: " << inicio->peso << endl;
        int opc = 0;
        cout << "\t¿DESEA ELIMINAR EL PAQUETE?\n\t1.- SI\n\t2.- NO\n\tINGRESAR UNA OPCION: ";
        cin>>opc;
        if(opc == 1)
        {
            cout << "\n\t¿REALMENTE DESEA ELIMINAR EL PAQUETE?\n\t1.- SI\n\t2.- NO\n\tINGRESAR UNA OPCION: ";
            cin>>opc;
            if(opc == 1)
            {
                cout << "\tPAQUETE ELIMINADO" << endl;
                inicio = inicio->siguiente;
            }
            else
            {
                cout << "\tREGRESANDO AL MENU PRINCIPAL" <<endl;
            }
        }
        else
        {
            cout << "\tREGRESANDO AL MENU PRINCIPAL" <<endl;
        }
    }
}

void Paqueteria::mostrar()
{
    if(vacia())
    {
        cout << "\tNo hay paquetes" << endl;
    }
    else
    {
        Paquete *tempM = new Paquete();
        tempM = inicio;
        while(tempM != NULL)
        {
            cout << "\tId: " << tempM->id << endl;
            cout << "\tOrigen: " << tempM->origen << endl;
            cout << "\tDestino: " << tempM->destino << endl;
            cout << "\tPeso: " << tempM->peso << endl;
            cout << "\n";
            tempM = tempM->siguiente;
        }
    }
}

void Paqueteria::guardar()
{
    if(vacia())
    {
        cout << "\tNo hay paquetes" << endl;
    }
    else
    {
        ofstream archivo("Paqueteria.txt");
        if(archivo.is_open())
        {
            Paquete *tempG = new Paquete();
            tempG = inicio;
            while(tempG != NULL)
            {
                archivo << tempG->id << endl;
                archivo << tempG->origen << endl;
                archivo << tempG->destino << endl;
                archivo << tempG->peso << endl;
                tempG = tempG->siguiente;
            }
            cout << "\tPAQUETES GUARDADOS EXITOSAMENTE" << endl;
            archivo.close();
        }
        else
        {
            cout << "\tERROR EN LA APERTURA DEL ARCHIVO" <<  endl;
        }
    }
}

void Paqueteria::recuperar()
{
        string id;
        int newId;
        string origen;
        string destino;
        string peso;
        float newPeso;
        ifstream archivo("Paqueteria.txt");
        if(archivo.is_open())
        {
            getline(archivo,id);
            while(id != "") //!archivo.eof()
            {
                newId = stoi(id);
                getline(archivo,origen);
                getline(archivo,destino);
                getline(archivo,peso);
                newPeso = stof(peso);
                cout << "ID: "<< newId << endl;
                cout << "ORIGEN: " << origen << endl;
                cout << "DESTINO: " << destino << endl;
                cout << "PESO: " << newPeso << endl;
                //AGREGAMOS EL OBJETO PAQUETE
                Paquete *temp = new Paquete;
                temp->id = newId;
                temp->origen = origen;
                temp->destino = destino;
                temp->peso = newPeso;
                if(vacia())
                {
                    inicio = temp;
                }
                else
                {
                    temp->siguiente = inicio;
                    inicio = temp;
                }
                getline(archivo,id); //LEEMOS NUEVO ID
            }
            cout << "\tPAQUETES CARGADOS EXITOSAMENTE" << endl;
            archivo.close();
        }
        else
        {
            cout << "\tERROR EN LA APERTURA DEL ARCHIVO" <<  endl;
        }
}

int main()
{
    Paqueteria FedMex; //Creacion del objeto Paqueteria (La lista que almacenará paquetes)

    int opc = 0;
    cout<< "\t\tMENU PRINCIPAL\n" << endl;
    while(opc != -1)
    {
        cout << "\t1.- INSERTAR AL INICIO"<<endl;
        cout << "\t2.- ELIMINAR AL INICIO"<<endl;
        cout << "\t3.- MOSTRAR"<<endl;
        cout << "\t4.- GUARDAR ARCHIVO"<<endl;
        cout << "\t5.- RECUPERAR ARCHIVO"<<endl;
        cout << "\t6.- SALIR"<<endl;
        cout << "\tINGRESAR OPCION: ";
        cin>>opc;
        cin.get();
        system("cls");
        switch(opc)
        {
        case 1:
        {
            cout << "\tMENU INSERTAR AL INICIO" << endl;
            int opc1 = 0;
            while(opc1 != -1)
            {
                cout<< "\t1.- AGREGAR NUEVO PAQUETE\n\t2.- REGRESAR AL MENU ANTERIOR\n\tINGRESAR OPCION: ";
                cin>>opc1;
                switch(opc1)
                {
                case 1:
                {
                    cin.get();
                    system("cls");
                    cout << "\tAGREGAR NUEVO PAQUETE" << endl;
                    int id = 0;
                    string origen = "";
                    string destino = "";
                    float peso = 0.0;
                    cout<< "\tID: ";
                    cin>>id;
                    cin.ignore();
                    cout<< "\tOrigen: ";
                    getline(cin,origen);
                    cout<< "\tDestino: ";
                    getline(cin,destino);
                    cout<< "\tPeso: ";
                    cin>>peso;
                    FedMex.agregar(id, origen, destino, peso);
                    cout<<"\tPAQUETE AGREGADO"<<endl;
                }
                break;
                case 2:
                    {
                    cout<< "\tREGRESANDO AL MENU ANTERIOR..." <<endl;
                    opc1 = -1;
                }
                    break;
                default:
                    cout << "\tOPCION NO VALIDA, POR FAVOR INGRESE OTRA OPCION..." << endl;
                    break;
                }
            }
            break;
        }
        case 2:
            {
                cout << "\tMENU ELIMINAR AL INICIO" << endl;
                FedMex.eliminar();
            }
            break;
        case 3:
            {
                cout << "\tMENU MOSTRAR" << endl;
                FedMex.mostrar();
            }
            break;
        case 4:
            {
                cout << "\tGUARDAR ARCHIVO" << endl;
                FedMex.guardar();
            }
            break;
        case 5:
            {
                cout << "\tRECUPERAR ARCHIVO" << endl;
                FedMex.recuperar();
            }
            break;
        case 6:
            {
                cout << "\tSALIENDO..." << endl;
                opc = -1;
            }
            break;
        default:
            cout << "\tOPCION NO VALIDA, POR FAVOR INGRESE OTRA OPCION..." << endl;
            break;
        }
        cin.get();
        system("cls");
    }
    return 0;
}
