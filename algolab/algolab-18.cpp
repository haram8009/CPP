// 오셀로
#include<iostream>
using namespace std;

char arr[9][9];

void changeColors(int r,int c, int colors){
    char color = (colors==1)? 'X':'O';
    char oposcolor;
    oposcolor = (colors==0)? 'X':'O';
    if(r!=1){
        for(int i=r-1; i>=1; i--){
            if(i==r-1 && arr[i][c]==color){
                break;  
            }
            if(arr[i][c]==oposcolor){
                arr[i][c]='*';
                continue;
            }
            if(arr[i][c]=='+'){
                for(int j=i;j<r;j++){
                    if(arr[j][c]=='*'){
                        arr[j][c]=oposcolor;
                    }
                }
                break;
            }
            if(arr[i][c]==color){
                for(int j=i;j<r;j++){
                    if(arr[j][c]=='*'){
                        arr[j][c]=color;
                    }
                }
                break;
            }
        }
        for(int j=1;j<r;j++){
            if(arr[j][c]=='*'){
                arr[j][c]=oposcolor;
            }
        }
    }
    if(r!=8){
        for(int i=r+1; i<=8; i++){
            if(i==r+1 && arr[i][c]==color){
                break;  
            }
            if(arr[i][c]==oposcolor){
                arr[i][c]='*';
                continue;
            }
            if(arr[i][c]=='+'){
                for(int j=i;j>r;j--){
                    if(arr[j][c]=='*'){
                        arr[j][c]=oposcolor;
                    }
                }
                break;
            }
            if(arr[i][c]==color){
                for(int j=i;j>r;j--){
                    if(arr[j][c]=='*'){
                        arr[j][c]=color;
                    }
                }
                break;
            }
        }
        for(int j=8;j>r;j--){
            if(arr[j][c]=='*'){
                arr[j][c]=oposcolor;
            }
        }
    }
    if(c!=1){
        for(int i=c-1; i>=1; i--){
            if(i==c-1 && arr[r][i]==color){
                break;  
            }
            if(arr[r][i]==oposcolor){
                arr[r][i]='*';
                continue;
            }
            if(arr[r][i]=='+'){
                for(int j=i;j<c;j++){
                    if(arr[r][j]=='*'){
                        arr[r][j]=oposcolor;
                    }
                }
                break;
            }
            if(arr[r][i]==color){
                for(int j=i;j<c;j++){
                    if(arr[r][j]=='*'){
                        arr[r][j]=color;
                    }
                }
                break;
            }
        }
        for(int j=1;j<c;j++){
            if(arr[r][j]=='*'){
                arr[r][j]=oposcolor;
            }
        }
    }
    if(c!=8){
        for(int i=c+1; i<=8; i++){
            if(i==c+1 && arr[r][i]==color){
                break;  
            }
            if(arr[r][i]==oposcolor){
                arr[r][i]='*';
                continue;
            }
            if(arr[r][i]=='+'){
                for(int j=i;j>c;j--){
                    if(arr[r][j]=='*'){
                        arr[r][j]=oposcolor;
                    }
                }
                break;
            }
            if(arr[r][i]==color){
                for(int j=i;j>c;j--){
                    if(arr[r][j]=='*'){
                        arr[r][j]=color;
                    }
                }
                break;
            }
        }
        for(int j=8;j>c;j--){
            if(arr[r][j]=='*'){
                arr[r][j]=oposcolor;
            }
        }
    }

    int min;
    // left up
    min= (r-1<c-1)? r-1:c-1;
    if(r!=1 && c!=1){
        for(int ir=r-1, ic=c-1; ir>=1 && ic>=1; ir--, ic--){
            if(ir==r-1 && arr[ir][ic]==color){
                break;  
            }
            if(arr[ir][ic]==oposcolor){
                arr[ir][ic]='*';
                continue;
            }
            if(arr[ir][ic]=='+'){
                for(int jr=ir, jc=ic; jr<r || jc<c ;jr++,jc++){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=oposcolor;
                    }
                }
                break;
            }
            if(arr[ir][ic]==color){
                for(int jr=ir, jc=ic; jr<r||jc<c; jr++,jc++){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=color;
                    }
                }
                break;
            }
        }
        for(int jr=r-min, jc=c-min; jr<r||jc<c; jr++,jc++){
            if(arr[jr][jc]=='*'){
                arr[jr][jc]=oposcolor;
            }
        }
    }
    // right down
    min=(8-r<8-c)? 8-r:8-c;
    if(r!=8 && c!=8){
        for(int ir=r+1, ic=c+1; ir<=8 && ic<=8; ir++, ic++){
            if(ir==r+1 && arr[ir][ic]==color){
                break;  
            }
            if(arr[ir][ic]==oposcolor){
                arr[ir][ic]='*';
                continue;
            }
            if(arr[ir][ic]=='+'){
                for(int jr=ir, jc=ic; jr>r || jc>c ;jr--,jc--){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=oposcolor;
                    }
                }
                break;
            }
            if(arr[ir][ic]==color){
                for(int jr=ir, jc=ic; jr>r || jc>c; jr--,jc--){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=color;
                    }
                }
                break;
            }
        }
        for(int jr=r+min, jc=c+min; jr>r || jc>c; jr--, jc--){
            if(arr[jr][jc]=='*'){
                arr[jr][jc]=oposcolor;
            }
        }
    }
    // right up
    min=(r-1<8-c)? r-1:8-c;
    if(r!=1 && c!=8){
        for(int ir=r-1, ic=c+1; ir>=1 && ic<=8; ir--, ic++){
            if(ir==r-1 && arr[ir][ic]==color){
                break;  
            }
            if(arr[ir][ic]==oposcolor){
                arr[ir][ic]='*';
                continue;
            }
            if(arr[ir][ic]=='+'){
                for(int jr=ir, jc=ic; jr<r || jc>c ;jr++,jc--){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=oposcolor;
                    }
                }
                break;
            }
            if(arr[ir][ic]==color){
                for(int jr=ir, jc=ic; jr<r||jc>c; jr++,jc--){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=color;
                    }
                }
                break;
            }
        }
        for(int jr=r-min, jc=c+min; jr<r||jc>c; jr++,jc--){
            if(arr[jr][jc]=='*'){
                arr[jr][jc]=oposcolor;
            }
        }
    }
    // left down
    min=(8-r<c-1)? 8-r:c-1;
    if(r!=8 && c!=1){
        for(int ir=r+1, ic=c-1; ir<=8 && ic>=1; ir++, ic--){
            if(ir==r+1 && arr[ir][ic]==color){
                break;  
            }
            if(arr[ir][ic]==oposcolor){
                arr[ir][ic]='*';
                continue;
            }
            if(arr[ir][ic]=='+'){
                for(int jr=ir, jc=ic; jr>r || jc<c ;jr--,jc++){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=oposcolor;
                    }
                }
                break;
            }
            if(arr[ir][ic]==color){
                for(int jr=ir, jc=ic; jr>r || jc<c; jr--,jc++){
                    if(arr[jr][jc]=='*'){
                        arr[jr][jc]=color;
                    }
                }
                break;
            }
        }
        for(int jr=r+min, jc=c-min; jr>r || jc<c; jr--, jc++){
            if(arr[jr][jc]=='*'){
                arr[jr][jc]=oposcolor;
            }
        }
    }
}

void nOnX(){
    int nO=0, nX=0;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            if(arr[i][j] == 'O') nO++;
            else if(arr[i][j]=='X') nX++;
        }
    }
    cout << nX << " " << nO << " " << endl;
}

int main(){
    int testCase;
    cin >> testCase;
    for(int t=0; t<testCase; t++){
        // initialize
        for(int i=1; i<=8; i++){
            for(int j=1; j<=8; j++){
                arr[i][j] = '+';
            }
        }
        arr[4][4]='O';arr[5][5]='O';arr[4][5]='X';arr[5][4]='X';
        
        //game
        int n, r, c;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> r >> c;
            if(i%2==1) arr[r][c]='X'; //Black
            else arr[r][c]='O'; //White
            changeColors(r,c, i%2);
        }

        nOnX();
        for(int i=1; i<=8; i++){
                for(int j=1; j<=8; j++){
                    cout << arr[i][j];
                }
                cout << endl;
            }
    }
}