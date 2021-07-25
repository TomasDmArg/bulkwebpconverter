#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, lang;
    string textos[] = {"De: (ej. jpg/png/etc) ", "Cantidad de archivos: ", "Nombre de archivo: "}; 
    string texts[] = {"From: (e.g. jpg/png/etc) ","File quantity: ", "filename: "};
    string actual[] = {""};
    vector<string> files;
    cout<<"Idioma/Language\n Spanish: 0 \n English: 1 \n"; cin>>lang;
    if(lang == 0){
        for (int i = 0; i < sizeof(textos)/sizeof(textos[0]); i++){
            actual[i] = textos[i];
        }
    }else{
        for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++){
            actual[i] = texts[i];
        }
    }
    string type, from, to, res;
    cout<<actual[0];
    cin>>type;
    cout<<actual[1];
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<actual[2]<<" "; 
        string file;
        cin>>file;
        files.push_back(file);
    }
    system("mkdir output");
    for(int i = 0; i < n; i++){
        from = files[i] + "." + type; 
        to = files[i] + ".webp";
        res = "cwebp " + from + " -o  output/" + to;
        system(res.c_str());
    }
    system("start output");
}