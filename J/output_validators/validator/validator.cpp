#include<bits/stdc++.h>
using namespace std;
string readYESorNO(){
    char c;
    while(true){
        if((c = getchar())==EOF)return "";
        if(c!=' '&&c!='\n')break;
    }
    string res;
    while(true){
       // if(c<'0'||c>'1')throw "not 01 string";
        res = res + c ;
        if((c = getchar())==EOF)break;
        if(c==' '||c=='\n')break;
    }
    return res;
}
string readstring(){
    char c;
    while(true){
        if((c = getchar())==EOF)return "";
        if(c!=' '&&c!='\n')break;
    }
    string res;
    while(true){
        if(c<'0'||c>'1')throw "not 01 string";
        res = res + c ;
        if((c = getchar())==EOF)break;
        if(c==' '||c=='\n')break;
    }
    return res;
}
int AC(){
    printf("AC\n");
    return 42;
}
int WA(){
    printf("WA\n");
    return 43;
}
int main(int argc, char *argv[]){
    string input_file = string(argv[1]);
    string answer_file = string(argv[2]);
    fstream input,answer;
    input.open(input_file);
    answer.open(answer_file);
    try{
        string str=readYESorNO();
        string ans;
        answer>>ans;
        if(ans!=str)throw "wa";
        string team_output="0"+readstring();
        if(str=="NO"){
            if(team_output=="0")return AC();
            throw "NO with exceed output";
        }
        int n,m;
        input>>n>>m;
        if(team_output.size()!=n+1)throw "wrong length";
        for(int i=0;i<m;i++){
            int a,b,c;
            input>>a>>b>>c;
            if(c==1){
                if(team_output[b]=='0'&&team_output[a]=='0')throw "wrong edge 1";
            }
            if(c==2){
                if(team_output[b]=='1'&&team_output[a]=='1')throw "wrong edge 2";
            }
            if(c==3){
                if(team_output[b]==team_output[a])throw "wrong edge 3";
            }
            if(c==4){
                if(team_output[b]!=team_output[a])throw "wrong edge 4";
            }
        }
        return AC();
    }
    catch(...){
        return WA();
    }
}