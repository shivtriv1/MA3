#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    //

    map<string, TwitterData> nameTwitMap, emailTwitMap;

    for (int i = 0; i < 5; ++i)
    {
        nameTwitMap[twitter_data[i].getUserName()] = twitter_data[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        emailTwitMap[twitter_data[i].getUserName()] = twitter_data[i];
    }


    auto it = nameTwitMap.find("savage1");

    if (it != nameTwitMap.end())
    {
        cout << "username: " << it->first << endl;
        cout << "name: " << it->second.getActualName() << endl;
        cout << "first name: " << it->second.getEmail() << endl;
        cout << "email: " << it->second.getEmail() << endl;
        cout << "number of tweets: " << it->second.getNumTweets() << endl;
        cout << "category: " << it->second.getCategory() << endl << endl;
    }

    nameTwitMap.erase("savage1");


    it = emailTwitMap.begin();

    if(it != emailTwitMap.end())
    {
        if (it->second.getEmail() == "kat@gmail.com")
        {
            cout << "username: " << it->first << endl;
            cout << "name: " << it->second.getActualName() << endl;
            cout << "first name: " << it->second.getEmail() << endl;
            cout << "email: " << it->second.getEmail() << endl;
            cout << "number of tweets: " << it->second.getNumTweets() << endl;
            cout << "category: " << it->second.getCategory() << endl;
        }
        else
        {
            ++it;
        }
    }

    emailTwitMap.erase("kat@gmail.com");









    return 0;
}