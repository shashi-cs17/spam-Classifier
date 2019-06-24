#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)

map<string,bool> tmp;
vector<string> vocab;
map<string,double> data[2];
int total = 0;

vector<string> tokenize(string line){
    vector<string> vtmp;
    string tt="";
    for(char ch:line){
        if(ch>'z' || ch<'a'){
            if(tt.length()>=1) vtmp.push_back(tt);tt="";
        }
        else{
            tt+=ch;
        }
    }
    if(tt.length()>=1) vtmp.push_back(tt);
    return vtmp;
}
void mapData(vector<string> v, int k){
    for(string s:v){
        if(tmp[s]==false){
            total++;
            tmp[s]=true;vocab.push_back(s);
            data[0][s]=(double)0;data[1][s]=(double)0;
        }
        data[k][s] = data[k][s]+(double)1;
    }
}

int main(){
    fastio;
    string header,line;
    ifstream in,fin;
    ofstream out,fout;
    out.open("/home/trent/Dev/octave/projData/dataMap.txt");
    fout.open("/home/trent/Dev/octave/projData/notAppear.txt");
    fin.open("/home/trent/Dev/octave/projData/hamnames.txt");
    if(fin.is_open() == false || out.is_open() ==false || fout.is_open() == false){
        cout<<"error"<<endl;return 0;
    }
    int ind=0;fout<<"ham"<<endl;
    cout<<"---------Ham mails----------"<<endl;
    while(getline(fin,header)){
        ind++;
        if(ind%100 == 0)cout<<"cleared --> "<<ind<<endl;
        if(header.length() <= 1)break;
        if(header == "END")break;
        in.open(("/home/trent/Dev/octave/projData/enron1/ham/"+header).c_str());
        if(!in.is_open()){
            fout<<ind<<endl;continue;
        }
        while(getline(in,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            mapData(tokenize(line),0);
        }
        in.close();
    }
    cout<<"found end at = "<<ind<<endl;
    fin.close();
    //
    fin.open("/home/trent/Dev/octave/projData/spamnames.txt");
    if(!fin.is_open()){
        out.close();fout.close();return 0;
    }
    ind=0;fout<<"spam"<<endl;
    cout<<"---------spam mails----------"<<endl;
    while(getline(fin,header)){
        ind++;
        if(ind%100 == 0)cout<<"cleared --> "<<ind<<endl;
        if(header.length() <= 1)break;
        if(header == "END")break;
        in.open(("/home/trent/Dev/octave/projData/enron1/spam/"+header).c_str());
        if(!in.is_open()){
            fout<<ind<<endl;continue;
        }
        while(getline(in,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            mapData(tokenize(line),1);
        }
        in.close();
    }
    cout<<"found end at = "<<ind<<endl;fin.close();
    tmp.clear();
    double ps;
    for(string x : vocab){
        ps = data[1][x]/(data[0][x]+data[1][x]);
        out<<x<<" "<<ps<<endl;
    }
    out.close();
    fout.close();
    cout<<total<<endl;
    return 0;
}
