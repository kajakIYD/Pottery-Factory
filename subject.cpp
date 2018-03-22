#include "subject.h"

using namespace std;

void Subject::Attach(MainWindow *obj)
{
    obs_list.push_back(obj);
}

void Subject::Notify()          // ???????
{
    for(vector<MainWindow*>::const_iterator iter = obs_list.begin(); iter != obs_list.end(); ++iter)
    {
        if(*iter != 0)
        {
           // (*iter)->Update();      // ???????
        }
    }
}
