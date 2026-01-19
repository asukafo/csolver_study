
#include <cstdint>
#include <csolver.h>
#include <string>

class test : public csolver::rand_obj_base 
{
public:
	test(csolver::rand_obj_base* parent = nullptr, const char* name="test")
		: csolver::rand_obj_base(parent, name)
		, x(this, "x")
		, y(this, "y")
	{
		define_constraints();
	}

public: 
	csolver::rand_var<uint32_t> x;
	csolver::rand_var<uint32_t> y;

	void define_constraints()
	{
		constraint ("x_y_c") ((
			x() < y()
		));
	}
};


int main(int argc, char* argv[])
{
	test t(nullptr, "t");
	
	t.randomize();

	std::cout << "x:" << t.x << ", y:" << t.y << std::endl;

	return 0;
}
