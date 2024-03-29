 

class TrieNode

{

public:

 

    char data;

    TrieNode* children[26];

    bool isTerminal;

 

    TrieNode(char ch)

    {

        data=ch;

 

        for(int i=0;i<26;i++)

        {

            children[i]=NULL;

        }

 

        isTerminal=false;

    }

};

 

class Trie

{

    TrieNode* root;

public:

 

    Trie()

    {

        root=new TrieNode('\0');

    }

 

    void insertUtil(TrieNode* root,string word)

    {

        if(word.size()==0){root->isTerminal=true;return;}

        if(root->children[word[0]-'a']==NULL)

        {

            root->children[word[0]-'a']=new TrieNode(word[0]);

        }

        insertUtil(root->children[word[0]-'a'],word.substr(1));

    }

 

    void insert(string word)

    {

        insertUtil(root,word);

    }

 

    bool searchUtil(TrieNode* root,string word)

    {

        if(word.size()==0){return root->isTerminal;}

        if(root->children[word[0]-'a']==NULL)

        {

            return false;

        }

        return searchUtil(root->children[word[0]-'a'],word.substr(1));

    }

 

    bool search(string word)

    {

        return searchUtil(root,word);

    }

 

    bool startsWith(string prefix)

    {

        TrieNode* temp=root;

        for(auto it:prefix)

        {

            if(temp->children[it-'a']==NULL)

            {

                return false;

            }

            temp=temp->children[it-'a'];

        }

        return true;

    }

};
