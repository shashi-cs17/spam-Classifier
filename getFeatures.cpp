#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mp make_pair


//
int offset=25;
int cntt=25;
double prec=0.5;
//
map<string,bool> tmp;
map<string,double> data;
string s;double ps;int total=0;
//
ifstream in,fin,din;
ofstream fout;
//

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
}

int buildMatrix(string fname){

    string header,line;
    map<string ,int> stx;
    set< pair<double,string> > hav;
    set< pair<double,string> >::iterator it;

    int ind = 0;

    while(getline(fin,header)){
        ind++;
        if(ind%500 == 0)cout<<"cleared --> "<<ind<<endl;
        if(header.length() <= 1)break;
        if(header == "END")break;
        in.open(("/home/trent/Dev/octave/projData/enron1/"+fname+"/"+header).c_str());
        if(!in.is_open()){
            cout<<"error in "<<fname<<" = "<<ind<<endl;continue;
        }
        //
        stx.clear();hav.clear();int tw=0;int havtw=0;
        while(getline(in,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            vector<string> v = tokenize(line);
            for(string sx:v){
                tw++;
                if(tmp[sx])havtw++,hav.insert(mp(data[sx],sx)),stx[sx] = stx[sx]+1;
            }
        }
        double rel= (double)0;int xrel=0;
        it = hav.lower_bound(mp(prec,"a"));
        while(it!=hav.end()){
            xrel = xrel + stx[(*it).second];it++;
        }
        rel = (double)xrel+(double)offset;rel = rel/(havtw-xrel+offset);
        // P(HAM | "word");
            it=hav.begin();int y=0;double dy;
            while(it!=hav.end()){
                if(y>=cntt)break;dy = (double)1 - (*it).first;
                dy = (double)(1+dy)*(double)(stx[(*it).second]+offset);dy = dy/(double)(tw+offset);
                fout<<dy<<" ";y++;it++;
            }
            dy = (double)offset/(double)(tw+offset);
            while(y<cntt){fout<<dy<<" ";y++;}
            //fout<<endl;
        // P(SPAM | "word");
            it = hav.end();y=0;
            while(it!=hav.begin()){
                if(y>=cntt)break;it--;dy = (*it).first;
                dy = (double)(1+dy)*(double)(stx[(*it).second]+offset);dy = dy/(double)(tw+offset);
                fout<<dy*rel<<" ";y++;
            }
            dy = (double)offset/(double)(tw+offset);
            while(y<cntt){fout<<dy*rel<<" ";y++;}
            fout<<endl;
        //
        in.close();
    }

    return ind;
}

int main(){
    fastio;
    //
    //------------------------------------------------------------->>>>>>>>>>>>>>>>>>>
    //
    string line;int opt=0;
    din.open("/home/trent/Dev/octave/projData/dataMap.txt");
    if(!din.is_open()){cout<<"canntopen"<<endl;return 0;}
    while(getline(din,line)){
        if(line.length()<=1)break;
        getData(line);
        //if(ps!=(double)0 && ps!=(double)1){
            data[s]=ps;
            tmp[s]=true;
            if(prec<=ps)opt++;
            //prec = ps;
            total++;
        //}
    }
    //prec = prec/(double)total;
    din.close();
    cout<<"total = "<<total<<endl;
    cout<<"precision = "<<opt<<endl;
    //
    //
    //------------------------------------------------------------->>>>>>>>>>>>>>>>>>>
    //
    //
    fout.open("/home/trent/Dev/octave/projData/hammat.txt");
    fin.open("/home/trent/Dev/octave/projData/hamnames.txt");
    if(fin.is_open() == false || fout.is_open() == false){
        cout<<"error"<<endl;return 0;
    }
    cout<<"---------Ham mails----------"<<endl;
    cout<<buildMatrix("ham")<<endl;cout<<"END"<<endl;
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
    cout<<"---------spam mails----------"<<endl;
    cout<<buildMatrix("spam")<<endl;cout<<"END"<<endl;
    fin.close();fout.close();

    return 0;
}
