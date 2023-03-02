#include <iostream>
#include <string>

#include <ilcp/cp.h>

int main(int argc, char *argv[]) {

    std::cout << "testing cp optimizer library" << std::endl;
    
    // Following example from "/cpoptimizer/examples/src/cpp/intro.cpp"
    IloEnv env;
    try {
        IloModel model(env);
        IloIntVar x(env, 5, 12, "x");
        IloIntVar y(env, 2, 17, "y");
        model.add(x + y == 17);
        model.add(x - y == 5);
        IloCP cp(model);
        cp.propagate();
        cp.out() << std::endl << "Propagate:" << std::endl;
        cp.out() << "x in " << cp.domain(x) << std::endl;
        cp.out() << "y in " << cp.domain(y) << std::endl << std::endl;
        if (cp.solve()) {
        cp.out() << std::endl << "Solution:" << std::endl;
        cp.out() << "x = " << cp.getValue(x) << std::endl;
        cp.out() << "y = " << cp.getValue(y) << std::endl;
        }
        cp.end();
    }
    catch (IloException& ex) {
        env.out() << "Caught: " << ex << std::endl;
    }
    env.end();

    return 0;
}
