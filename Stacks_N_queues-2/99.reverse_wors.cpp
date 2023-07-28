string reverseString(string &str){

    // Write your code here.    

    vector<string> v;

    string s="";

    for(int i=0;i<str.length();i++){

        if(str[i]==' '){

            if(s.length()!=0){

                v.push_back(s);

                s="";

            }

        }else{

            s.push_back(str[i]);

        }

    }

    if (s.length() != 0) {

        v.push_back(s);

    }

    reverse(v.begin(),v.end());

    string res="";

    for (int i = 0; i < v.size(); i++) {

        res += v[i];

        if (i != v.size() - 1) {

            res += ' '; 

        }

    }

    return res;

}

