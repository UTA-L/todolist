#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    ofstream fout;
    ifstream fin;
    string description;
    string task;
    string path = "todolist.txt";
    string temp_path = "temptodo.txt";
    string mark = " !!!";
    int num = 1;
    int num_of_task;
    int option = 5;
    while (option != 0)
    {
        cout << "---TO DO LIST---" << endl;
        cout << "1 - Add new task" << endl;
        cout << "2 - View Tasks" << endl;
        cout << "0 - Close the program" << endl;
        cout << "\nEnter: ";

        cin >> option;
        switch (option)
        {
        case 1:
            cin.ignore();
            cout << "\n Description: ";
            getline(cin, description);
            fout.open(path, ofstream::app);
            if (!fout.is_open())
            {
                cerr << "\nofstream error";
            }
            else
            {
                fout << description << "\n";
            }
            fout.close();
            break;
        case 2:
            cout << endl;
            fin.open(path);
            if (!fin.is_open())
            {
                cerr << "\nifstream error";
            }
            else
            {

                while (getline(fin, task))
                {

                    cout << num << ". " << task << endl;
                    num++;
                }
                num = 1;
                fin.close();

                cout << "\n1 - Check/Uncheck the task" << endl;
                cout << "2 - Delete the task" << endl;
                cout << "Any num - return" << endl;
                cout << "0 - Close the program" << endl;
                cout << "\nEnter: ";

                cin >> option;
                switch (option)
                {
                case 1:
                    fin.open(path);
                    fout.open(temp_path, ofstream::app);
                    if (!fout.is_open())
                    {
                        cerr << "\nofstream error";
                    }
                    else
                    {
                        int count = 1;
                        cout << "\nNumber of task: ";

                        cin >> num_of_task;
                        while (getline(fin, task))
                        {
                            if (count == num_of_task)
                            {
                                size_t pos = task.find(mark);
                                if (pos != string::npos)
                                {
                                    task.erase(pos, mark.length());
                                    fout << task << endl;
                                }
                                else
                                {
                                    fout << task + " !!!" << endl;
                                }
                            }
                            else
                            {
                                fout << task << endl;
                            }
                            count++;
                        }
                        fin.close();
                        fout.close();
                        if (remove(path.c_str()) != 0 || rename(temp_path.c_str(), path.c_str()) != 0);
                        {
                            cerr << "\nfile modification error";
                        }

                    }
                    break;
                case 2:
                    fin.open(path);
                    fout.open(temp_path, ofstream::app);
                    if (!fout.is_open())
                    {
                        cerr << "\nofstream error";
                    }
                    else
                    {
                        int count = 1;
                        cout << "\nNumber of task: ";

                        cin >> num_of_task;
                        while (getline(fin, task))
                        {
                            if (count != num_of_task)
                            {
                                fout << task << endl;
                            }

                            count++;
                        }
                        fin.close();
                        fout.close();
                        if (remove(path.c_str()) != 0 || rename(temp_path.c_str(), path.c_str()) != 0);
                        {
                            cerr << "\nfile modification error";
                        }

                    }
                    break;
                }
            }
            fin.close();
            break;

        case 0:
            break;

        }
        //cout << "\033[2J\033[1;1H"; - 1 вариант очистки консоли
        system("cls"); // - 2 вариант очистки консоли
    }
    return 0;
}