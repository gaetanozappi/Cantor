#include<iostream>
#include<math.h>
using namespace std;

unsigned long long int Cantor(unsigned long long int r,unsigned long long int c){ return ((c+r)*(c+r+1))/2+r; }

unsigned long long int Pos(char j,unsigned long long int n,char a[]){
    for(int i=0;i<n;i++) if(j == a[i]) return i;
}
/*
void Gen(unsigned long long int key,unsigned long long int n,unsigned long long int &cod,unsigned long long int &parol){
    unsigned long long int i,j,k;
    for(i=0; i<=key; i++){
        j = 0;
        do{
            k = Cantor(i,j);
            j++;
        }while(k < key);
        
        if(k == key){
            cod = i;
            parol = --j;
            return;
        }
    }
    return;
}
*/

void Inv(unsigned long long int key,unsigned long long int &cod,unsigned long long int &parol){
	unsigned long long int s = (unsigned long long int)((sqrt(1+8*key)-1)/2);
	cod = key-s*(s+1)/2;
	parol = s-cod;
}


int main(){
    
    string str;
    unsigned long long int i,n,select,temp,len,parol,key;
    
    cout << "Inserisci il numero di simboli dell'alfabeto: ";
    cin >> n;
    
    if(n > 0){
    
        char alph[n];
        for(i=0;i<n;i++){
            cout << "Inserisci il "<<i+1<<" simbolo: ";
            cin >> alph[i];
            //fflush(stdin);
        }
      
        cout << "\n0)Cripta\n1)Decripta\nSeleziona la tua opzione: ";
        cin >> select;
        cout << endl;
        
        do{
            
            if(select == 0){
                      
                cout << "Inserisci la stringa da codificare: ";
                cin >> str;
                len = str.length();
                
                if(len > 1) cout << str << " = (" << Pos(str[0],n,alph) << "," << Pos(str[1],n,alph) << ") ";
                temp =  Pos(str[0],n,alph);    
                for(i=1;i<len-1;i++){
                    cout << "-> (" << Cantor(temp,Pos(str[i],n,alph)) << "," << Pos(str[i+1],n,alph) << ") ";
                    temp = Cantor(temp,Pos(str[i],n,alph));
                }
                
                if(len > 1) cout << "-> ";
                cout << "(" << Cantor(temp,Pos(str[i],n,alph)) << "," << len << ") -> " << Cantor(Cantor(temp,Pos(str[i],n,alph)),len) << endl;  
            
            }else if(select == 1){
            
                cout << "Inserisci la chiave (il numero ottenuto dalla codifica): ";
                cin >> key;
                
                //Gen(key,n,temp,len);
                Inv(key,temp,len);
                
                unsigned long long int txt[len];
                txt[len-1] = temp;
                
                cout << key << " -> (" << txt[len-1] << "," << len << ") ";
                temp = txt[len-1];
        
                for(i=0;i<len-1;i++){
                    Inv(temp,parol,txt[len-i-1]);
                    temp = parol;
                    cout << "-> (" << parol << "," << txt[len-i-1] << ") ";
                }
                
        		txt[0] = temp;
                cout << "= ";
                for(i=0;i<len;i++) cout << alph[txt[i]];
                cout << endl;
                
            }
            cout << "\n0)Cripta\n1)Decripta\n2)Per uscire\nSeleziona la tua opzione: ";
            cin >> select;
            cout << endl;
            
        }while(select != 2);
    }

    getchar();
    getchar();
    return 0;
}
