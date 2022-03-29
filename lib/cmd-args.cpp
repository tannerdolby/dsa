#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    cout << "Executable: " << argv[0] << endl;
    cout << "Number of cmd-line args: " << argc << endl;

    for (int i=1; i < argc; i++) {
        cout << argv[i] << endl;
    }

    return 0;
}