// **** include files ****
#include <iostream>
#include <thread>
#include <initializer_list>
#include <vector>


// **** namespaces ****
using namespace std;


//
// Thread function using a template.
//
template<typename Type>
void threadFn   (
                //initializer_list<int> il
                vector<int> iv
                )

{

    // **** welcome message ****
    cout << "threadFc <<< entering\n";

    // **** display our thread id ****
    cout << "threadFc <<< threadID: " << this_thread::get_id() << endl;

    // **** display the Type ****
    cout << "threadFn <<< Type ==>" << typeid(Type).name() << "<== line: " << __LINE__ << endl;

    // **** set the delay based on the Type ****
    long delay = 0;

    // **** int ****
    if (strcmp(typeid(Type).name(), "int") == 0)
    {

        // ???? ????
        cout << "threadFn <<< Type: int\n";

        // **** set the delay ****
        delay = 3;
    }

    // **** float ****
    else if (strcmp(typeid(Type).name(), "float") == 0)
    {

        // ???? ????
        cout << "threadFn <<< Type: float\n";

        // **** set the delay ****
        delay = 5;
    }

    // **** class std::initializer_list<int> ****
    else if (strcmp(typeid(Type).name(), "class std::initializer_list<int>") == 0)
    {

        // ???? ????
        cout << "threadFn <<< Type: class std::initializer_list<int>\n";

        // **** set the delay ****
        delay = 7;

        //// **** display the size of the list ****
        //cout << "threadFn <<< il.size(): " << il.size() << endl;
    }

    // **** ****
    else if (strcmp(typeid(Type).name(), "class std::vector<int,class std::allocator<int> >") == 0)
    {

        // ???? ????
        cout << "threadFn <<< Type: class std::vector<int,class std::allocator<int> >\n";

        // **** set delay ****
        delay = 11;

        // **** display the size of the vector ***
        cout << "threadFn <<< iv.size(): " << iv.size() << endl;
    }

    // **** unknown type ****
    else
    {

        // ???? ????
        cout << "threadFn <<< Type: unknown\n";

        // **** set the delay ****
        delay = 13;
    }

    // ???? ????
    cout << "threadFn <<< delay: " << delay << endl;

    // **** pretend to do some work based on the Type ****
    cout << "threadFc <<< doing work (sleeping) ...\n";
    this_thread::sleep_for(chrono::seconds(delay));
    cout << "threadFc <<< done with work\n";

    // **** bye bye message ****
    cout << "threadFc <<< bye bye\n";
}


//
// Main entry point.
//
int main    (
            )
{

    // **** welcome message ****
    cout << "main <<< entering\n";

    // **** display our thread id ****
    cout << "main <<< threadID: " << this_thread::get_id() << endl;

    // **** initialize a list of integers ****
    initializer_list<int> il = { 1,2,3,4,5 };

    // **** initialize a vector ****
    vector<int> iv = { 1,2,3,4,5,6,7 };

    // **** call the thread function ****
    //thread t1 { threadFn<int> };
    //thread t1 { threadFn<initializer_list<int>> };
    //thread t1 { threadFn, il };
    //thread t1 { threadFn<initializer_list<int>>, il};

    //thread t1{ threadFn<vector<int>>, {1, 2, 3} };
    thread t1 { threadFn<vector<int>>, iv };

    //// **** call the thread function ****
    //thread t2{ threadFn<float> };

    // **** join the thread function ****
    cout << "main <<< witing for thread(s) to complete ...\n";
    t1.join();
    //t2.join();
    cout << "main <<< threads completed\n";

    // **** bye bye message ****
    cout << "main <<< bye bye\n";

    // **** ****
    return 0;
}
