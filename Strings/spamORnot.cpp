#include<bits/stdc++.h>
using namespace std;
string toLowerCase(string & s){
    string result = s;
    transform(result.begin(),result.end(),result.begin(),::tolower);
    return result;
}
vector<string>identifySpamApplications(vector<string>& applicantSubjects, vector<string>& spamKeywords){
      vector<string>result;
      unordered_set<string>spamset;

      for(string & word : spamKeywords){
        spamset.insert(toLowerCase(word));
      }

      for(string subject : applicantSubjects){
        subject = toLowerCase(subject);
        stringstream ss(subject);
        string word;
        int cnt =0;
        while (ss>> word)
        {
           if(spamset.count(word)){
             cnt++;
           }
        }

        if(cnt >=2){
            result.push_back("spam");
        }else{
            result.push_back("not spam");
        }
        
      }
      return result;
}
int main() {
    vector<string> applicantSubjects = {
        "Sales Job Inquiry",
        "Quick Money Opportunity",
        "Earn Cash Fast",
        "Quick offer requested"
    };

    vector<string> spamKeywords = {"quick", "money", "earn", "cash"};

    vector<string> ans = identifySpamApplications(applicantSubjects, spamKeywords);

    for (string s : ans)
        cout << s << endl;

    return 0;
}
