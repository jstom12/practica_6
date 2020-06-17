#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cuerpo.h>
#include <string>


using namespace std;
vector<string> separar_string(string,char);

int main()
{
    /*
    El archivo que se recibe tiene la siguiente estrucuta:
    POSICION EN X; POSICION EN Y; RADIO; MASA; VELOCIDAD INICIAL EN X; VELOCIDAD INICIAL EN Y

    NOTESE QUE CADA VALOR ESTA SEPARADO POR UN ;

    */
    vector<cuerpo> cuerpos;
    ifstream archivo("datos.txt");
    ofstream escritura("resultados.txt");
    if(!archivo.is_open())ofstream archivo("datos.txt");
    string linea;
    int id=0,delta_t=1;
    while(getline(archivo,linea))
    {
        /*
        Creando un vector con todos los cuerpos que se entreguen en el archivo .txt
        esto para hacer mas facil las pruebas. se reciben los datos en string y se convierten
        a double en el ciclo for por medio de la funcion stod que viene incorporada en la libreria
        <string>.
        */
        vector<string> datos;
        datos = separar_string(linea,';');
        vector<double> datos_double;
        for(int i=0;i<6;i++)
        {
            datos_double.push_back(stod(datos[i]));
        }

        cuerpo auxiliar_agregar_a_vector(datos_double[0],datos_double[1],datos_double[2],datos_double[3],datos_double[4],datos_double[5],id);
        cuerpos.push_back(auxiliar_agregar_a_vector);
        id++;
    }
    for(int j=0;j<101;j++)
    {
        for(int l=0;l<id+1;l++)
        {
            escritura << cuerpos[l].getPosx() <<"    "<< cuerpos[l].getPosy() << "    ";
        }
        escritura << endl;
        vector<cuerpo>::iterator it;
        it=cuerpos.begin();
        while(it!=cuerpos.end())
        {
            for(int i=0;i<id+1;i++)
            {
                if(i!=it->getId())
                {
                    it->actualizar_velocidad(cuerpos[i].getPosx(),cuerpos[i].getPosy(),cuerpos[i].getMasa());
                }
            }
            it->actualizar_posicion(1);
            it++;
        }
    }
    archivo.close();
    escritura.close();


}
vector<string> separar_string(string linea,char separador)
{
    /*
    La funcion de separar string fue necesaria para facilitar el manejo del archivo de texto
    por lo que se encontró esta funcion en internet que no es propia pero usa un elemento de la
    clase stringstream que recorre un string cada que encuentro un char declarado en la funcion
    y se añade a un vector<string> para luego retornar ese vector<string>.
    */
    vector<string> string_separate;
    stringstream strTemp(linea);
    string segment;
    while(getline(strTemp,segment,separador))
    {
        string_separate.push_back(segment);
    }
    return string_separate;
}
