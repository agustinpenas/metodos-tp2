#ifndef COVARIANZA_H
#define COVARIANZA_H

#include "Matriz.h"
#include "Auxiliares.h"

typedef double autovalor;
typedef vector<double> autovector;
typedef pair<autovalor, autovector> parAutov;

class MatrizCovarianza{

	public:
        // Vector de vectores que se pasa por referencia, se puede cambiar.
        MatrizCovarianza(Matriz &v);

        //Devuelve V traspuesta (LOS AUTOVECTORES ESTÁN COMO FILAS)y un vector de los autovalores que irían en la diagonal, eso no se si es
        //necesario, podría sacarse
        pair<Matriz, vector<autovalor> > Diagonalizar(int alpha, int itersMetodoPotencia);

        Matriz cov;
        vector<double> media;
    private:

        vector<double> calcularMedia(Matriz &v);

        void restarMedia(Matriz &v);
        Matriz producto_traspuesta_orig(Matriz &v);

        friend std::ostream& operator<<(std::ostream& os, const MatrizCovarianza &c){
            c.mostrar(os);
            return os;
        };

        void mostrar(std::ostream& os) const{
            os << this->cov;
        }
};

#endif