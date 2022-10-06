struct Node

{

    Node* links[26];

    int cntPrefix;

    Node(){

        for(int i=0;i<26;i++)

            links[i]=NULL;

        cntPrefix=0;

    }

    

    bool containskey(char ch){

        return links[ch-'a']!=NULL;

    }

    

    Node* get(char ch){

        return links[ch-'a'];

    }

    void put(char ch, Node* node){

        links[ch- 'a']= node;

    }

    void increasePrefix(){

        cntPrefix++;

    }

    int getPrefix(){

        return cntPrefix;

    }

};

 

class Trie

{

    Node* root;

    public:

    Trie(){

        root=new Node();

    }

    void insert(string s){

        Node* node=root;

        for(int i=0;i<s.size();i++){

            if(node->containskey(s[i])==false){

                node->put(s[i], new Node());

            }

            node=node->get(s[i]);

            node->increasePrefix();

        }

    }

    int get(string s){

        Node* node=root;

        for(int i=0;i<s.size();i++){

            if(node->containskey(s[i])==false){

                return 0;

            }

            node=node->get(s[i]);

        }

        return node->getPrefix();

    }

};

 

class Solution{

public:

    vector<int> prefixCount(int n, int q, string li[], string query[])

    {

        // code here

        Trie trie;

        for(int i=0;i<n;i++){

            trie.insert(li[i]);

        }

        vector<int> ans;

        for(int i=0;i<q;i++){

            ans.push_back(trie.get(query[i]));

        }

        return ans;

    }

};
