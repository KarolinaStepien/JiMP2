//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

using algebra::Matrix;

//stod
complex<double> funkcja(string value_s) {
    string real = value_s.substr(0,value_s.find('i'));
    string imaginary = value_s.substr(value_s.find('i')+1,value_s.length());
    double r = stod(real);
    double i = stod(imaginary);
    complex<double> c;
    c.real(r);
    c.imag(i);
    return c;
}
//zamiana z Matrix m("[1i3 2i5 3; 3 4 5; 6 7 8]") na tablice dwuwymiarowa
/*Matrix::Matrix(string uuu) {
    long semicolons = count(uuu.begin(), uuu.end(), ';');
    string section = uuu.substr(0, uuu.find(";"));
    long spaces = count(section.begin(), section.end(), " ");
    rows = int(semicolons + 1);
    columns = int(spaces + 1);

    complex<double> **table = new complex<double> *[rows];
    for (int i = 0; i < rows; i++) {
        table[i] = new complex<double>[columns];
    }
    tab = table;

    string one = uuu.substr(1, uuu.length() - 2); //1i3 2i5 3; 3 4 5; 6 7 8
    regex pattern{R"((\+|-)*\w+\.\w*\s*(\+|-)*\s*\w*\.*\w*)"};
    smatch matches;
    int r = 0, c = 0;
    while (regex_search(one, matches, pattern)) {
        for (auto match:matches) {
            string x = match.str();
            tab[r][c] = funkcja(x);
            c++;
            if (c > columns - 1) {
                c = 0;
                r++;
            }
        }
        one = matches.suffix().str();
    }
}*/
//zamiana z initializer_list na tablice dwuwymiarowa
/*Matrix::Matrix(std::initializer_list<vector<complex<double>>> cosik){
    cout<<"udało sie costam"<<endl;
    int n=0;
    int m=0;
    for(auto i=cosik.begin(); i!=cosik.end();i++){
        n++;
        m=0;
        for(auto j=i->begin();j!=i->end();j++){
            m++;
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    cout<<n<<endl;
    cout<<m<<endl;
    Matrix(n, m);
    n=0;
    m=0;
    for(auto l=cosik.begin(); l!=cosik.end();l++){
        cout<<"stage1"<<endl;
        n++;
        m=0;
        for(auto k=l->begin();k!=l->end();k++){
            cout<<"stage2"<<endl;
            m++;
            tab[1][1]=*k;
        }
        cout<<endl;
    }
}*/
//konstruktor bezparametrowy
Matrix::Matrix():rows(0),columns(0),tab(NULL) {}
//konstruktor parametrowy
Matrix::Matrix(int rows_, int columns_){
    this->rows = rows_;
    this->columns = columns_;
    //tab = NULL;
    this->tab = new complex<double>*[rows_];
    for (int i=0; i<rows_; i++){
        this->tab[i] = new complex<double>[columns_];
    }
}
//destruktor
Matrix::~Matrix(){
    for (int i=0; i<rows; i++) {
        delete [] tab [i];
    }
    delete[] tab;
}
//konstruktor kopiujacy
Matrix::Matrix(const Matrix &matrix){
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    complex<double> **new_tab = new complex<double> *[this->rows];
    for (int i=0; i<this->rows; i++){
        new_tab[i] = new complex<double>[this->columns];
    }
    for (int i=0; i<this->rows; i++)
    {
        for (int j=0;j<this->columns; j++)
        {
            new_tab[i][j]=matrix.tab[i][j];
        }
    }
    tab = new_tab;
}
//operator przypisania kopiujacy
Matrix & Matrix::operator=(const Matrix& matrix) {
    if (this == &matrix) {
        return *this;
    }
    for (int i=0; i<this->rows; i++)
    {
        delete [] tab [i];
    }
    delete [] tab;

    this->rows = matrix.rows;
    this->columns = matrix.columns;
    complex<double> **new_tab = new complex<double> *[this->rows];
    for (int i=0; i< this->rows; i++)
        new_tab[i]=new complex<double> [this->columns];

    for (int i=0; i<this->rows; i++)
    {
        for (int j=0;j<this->columns; j++)
        {
            new_tab[i][j]=matrix.tab[i][j];
        }
    }
    tab = new_tab;
}
//funkcja tworzaca macierz
void Matrix::Create_Matrix() {
    string nana;
    int columns;
    int rows;
    cout << "Podaj ilosc wierszy macierzy: " << endl;
    cin >> rows;
    cout << "Podaj ilosc kolumn macierzy: " << endl;
    cin >> columns;
    this->rows = rows;
    this->columns = columns;

    //alokacja pamieci
    this->tab = new complex<double> *[rows];
    for(int i=0;i<rows;i++){
        this->tab[i] = new complex<double> [columns];
    }

    //wypelnianie tablicy
    cout << "Podaj elementy macierzy: " << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            //cin >> this->tab[i][j];
            cin >> nana;
            this->tab[i][j] = funkcja(nana);
        }
    }
}
//funkcja printujaca macierz
void Matrix::Print_Matrix() {
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++) {
            cout << this->tab[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//funkcja dodajaca macierze
Matrix Matrix::Addition(const Matrix &m2) const{
    Matrix sum(this->rows, this->columns);
    if(this->rows==m2.rows  && this->columns==m2.columns){
        /*sum.columns=this->columns;
        sum.rows=this->rows;
        sum.tab = new complex<double> *[sum.rows];
        for(int i=0;i<sum.rows;i++) {
            sum.tab[i] = new complex<double>[sum.columns];
        }*/
        for(int i=0;i<sum.rows;i++) {
            for(int j=0;j<sum.columns;j++){
                sum.tab[i][j]=this->tab[i][j]+m2.tab[i][j];
            }
        }
    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return sum;
}
//funkcja odejmujaca macierze
Matrix Matrix::Subtraction(const Matrix &m2) const{
    Matrix sub(this->rows, this->columns);
    if(this->rows==m2.rows  && this->columns==m2.columns){
        /*sub.columns=this->columns;
        sub.rows=this->rows;
        sub.tab = new complex<double> *[sub.rows];
        for(int i=0;i<sub.rows;i++) {
            sub.tab[i] = new complex<double>[sub.columns];
        }*/
        for(int i=0;i<sub.rows;i++) {
            for(int j=0;j<sub.columns;j++){
                sub.tab[i][j]=this->tab[i][j]-m2.tab[i][j];
            }
        }
    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return sub;
}
//funkcja mnozaca macierze
Matrix Matrix::Multiplication(const Matrix &m2) const{
    Matrix product(this->rows, m2.columns);
    if(this->rows==m2.columns  && this->columns==m2.rows){
        /*product.rows=this->rows;
        product.columns=m2.columns;
        product.tab = new complex<double> *[product.rows];
        for(int i=0;i<this->rows;i++) {
            product.tab[i] = new complex<double>[product.columns];
        }*/
        for (int i=0;i<this->rows;i++) {
            for (int j = 0; j < m2.columns; j++) {
                for (int k = 0; k < this->columns; k++) {
                    product.tab[i][j] += this->tab[i][k] * m2.tab[k][j];
                }
            }
        }
    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return product;
}
//funkcja potegujaca macierze
Matrix Matrix::Exponentation(int p){
    Matrix power(this->rows, this->columns);
    if(this->rows==this->columns) {
        /*power.tab = new complex<double> *[this->rows];
        for(int i=0;i<this->rows;i++) {
            power.tab[i] = new complex<double>[this->columns];
        }*/
        if (p == 0) {
            for (int j = 0; j < this->rows; j++) {
                for (int k = 0; k < this->columns; k++) {
                    if (j == k) {
                        power.tab[j][k] = 1;
                    } else {
                        power.tab[j][k] = 0;
                    }
                }
            }
        } else {
            Matrix local_this(*this);
            Matrix helper(*this);
            while (p > 1) {
                local_this = local_this.Multiplication(helper);
                p--;
            }
            power = local_this;
        }

    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return power;
}