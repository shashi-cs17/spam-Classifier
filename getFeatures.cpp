#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)

map<string,bool> tmp;
map<string,double> data;
string s;double ps;int total=0;

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

void getData(string line){
    string tt="";
    for(char ch:line){
        if(ch == (char)32){
            s=tt;tt="";
        }
        else{
            tt+=ch;
        }
    }
    ps = atof(tt.c_str());
    //return vtmp;
}


int main(){
    fastio;
    //
    double as[10];
    multiset<double> stx;
    multiset<double>::iterator it;
    //
    string header,line;
    ifstream in,fin,din;
    ofstream fout;
    din.open("/home/trent/Dev/octave/projData/dataMap.txt");
    if(!din.is_open()){cout<<"canntopen"<<endl;return 0;}
    while(getline(din,line)){
        if(line.length()<=1)break;
        getData(line);
        if(ps!=(double)0 && ps!=(double)1){
            data[s]=ps;
            tmp[s]=true;
            total++;
        }
    }
    din.close();
    cout<<"total = "<<total<<endl;
    //
    fout.open("/home/trent/Dev/octave/projData/hammat.txt");
    fin.open("/home/trent/Dev/octave/projData/hamnames.txt");
    if(fin.is_open() == false || fout.is_open() == false){
        cout<<"error"<<endl;return 0;
    }
    int ind=0;//fout<<"ham"<<endl;
    cout<<"---------Ham mails----------"<<endl;
    while(getline(fin,header)){
        ind++;
        if(ind%500 == 0)cout<<"cleared --> "<<ind<<endl;
        if(header.length() <= 1)break;
        if(header == "END")break;
        in.open(("/home/trent/Dev/octave/projData/enron1/ham/"+header).c_str());
        if(!in.is_open()){
            cout<<"error in ham = "<<ind<<endl;continue;
        }
        stx.clear();
        while(getline(in,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            vector<string> v = tokenize(line);
            for(string sx:v){
                if(tmp[sx])stx.insert(data[sx]);
            }
        }
        // P(HAM | "word");
            it=stx.begin();int y=0;double dy;
            while(it!=stx.end()){
                if(y>=10)break;dy = (double)1 - (*it);fout<<dy<<" ";y++;it++;
            }
            while(y<10){fout<<0<<" ";y++;}
            //fout<<endl;
        // P(SPAM | "word");
            it = stx.end();y=0;
            while(it!=stx.begin()){
                if(y>=10)break;it--;fout<<(*it)<<" ";y++;
            }
            while(y<10){fout<<0<<" ";y++;}
            fout<<endl;
        //
        in.close();
    }
    cout<<"found end at = "<<ind<<endl;
    fin.close();fout.close();
    //
    //
    //------------------------------------------------------------->>>>>>>>>>>>>>>>>>>
    //
    //
    fout.open("/home/trent/Dev/octave/projData/spammat.txt");
    fin.open("/home/trent/Dev/octave/projData/spamnames.txt");
    if(fin.is_open() == false || fout.is_open() == false){
        cout<<"error"<<endl;return 0;
    }
    ind=0;//fout<<"spam"<<endl;
    cout<<"---------spam mails----------"<<endl;
    while(getline(fin,header)){
        ind++;
        if(ind%300 == 0)cout<<"cleared --> "<<ind<<endl;
        if(header.length() <= 1)break;
        if(header == "END")break;
        in.open(("/home/trent/Dev/octave/projData/enron1/spam/"+header).c_str());
        if(!in.is_open()){
            cout<<"error in spam = "<<ind<<endl;continue;
        }
        stx.clear();
        while(getline(in,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            vector<string> v = tokenize(line);
            for(string sx:v){
                if(tmp[sx])stx.insert(data[sx]);
            }
        }
        // P(HAM | "word");
            it=stx.begin();int y=0;double dy;
            while(it!=stx.end()){
                if(y>=10)break;dy = (double)1 - (*it);fout<<dy<<" ";y++;it++;
            }
            while(y<10){fout<<0<<" ";y++;}
            //fout<<endl;
        // P(SPAM | "word");
            it = stx.end();y=0;
            while(it!=stx.begin()){
                if(y>=10)break;it--;fout<<(*it)<<" ";y++;
            }
            while(y<10){fout<<0<<" ";y++;}
            fout<<endl;
        //
        in.close();
    }
    cout<<"found end at = "<<ind<<endl;
    fin.close();fout.close();

    return 0;
}
