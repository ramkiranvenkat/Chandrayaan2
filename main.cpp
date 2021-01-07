#include <iostream>
#include <fstream>
//#include "dataAdv.h"

class binaryFile
{
	public:
		binWrite();
		binWrite(char* );
		binWrite(string );
		~binWrite();

		binaryFile& operator= (const binaryFile& );	

		bool openFile(char* );
		bool openFile(string );

		bool closeFile(char* );
		bool closeFile(string );
		
		void wb(bool );
		void wc(char );
		void ws(string );
		void wi(int );
		void wf(float );
		void wd(double );
		void wm(Mat );
		void wq(Quat );
	
		void wb(int ,bool* );
		void wc(int ,char* );
		void wi(int ,int* );
		void wf(int ,float* );
		void wd(int ,double* );

		void wbAt(bool 		,size_t ,char );
		void wcAt(char 		,size_t ,char );
		void wsAt(string 	,size_t ,char );
		void wiAt(int 		,size_t ,char );
		void wfAt(float 	,size_t ,char );
		void wdAt(double 	,size_t ,char );
		void wmAt(Mat 		,size_t ,char );
		void wqAt(Quat 		,size_t ,char );

		void wbAt(int ,bool* 		,size_t ,char );
		void wcAt(int ,char* 		,size_t ,char );
		void wiAt(int ,int* 		,size_t ,char );
		void wfAt(int ,float* 		,size_t ,char );
		void wdAt(int ,double* 		,size_t ,char );


		bool	rb();
		char	rc();
		string	rs();
		int	ri();
		float	rf();
		double 	rd();
		Mat	rm(int ,int );
		Quat	rq();

		bool*	rb(int );
		char*	rc(int );
		int*	ri(int );
		float*	rf(int );
		double*	rd(int );

		bool*	rbAt(int ,size_t ,char );
		char*	rcAt(int ,size_t ,char );
		int*	riAt(int ,size_t ,char );
		float*	rfAt(int ,size_t ,char );
		double*	rdAt(int ,size_t ,char );
		
		void 	setCursor(size_t ,char );
		size_t	Cursor();
		// operator << 
		// operator >>
		
		//double& operator()(unsigned int ,unsigned int );
		//double& operator()(unsigned int );
		
	private:
		char* fname;
		size_t seekPos;
		std::ofstream file;
};

using namespace std;
ofstream ofile("file.out",ios::binary);
int main()
{
	
	//data inp("");
	double array[6];
	for (int i=0;i<6;i++)
	{
		array[i] = i+1;
	}
	ofile.write(reinterpret_cast<char*>(array), sizeof(array));
	// address of array variable to be used
	ofile.close();

	double oa[3];
	ifstream ifile("file.out",ios::binary);
	ifile.seekg(3*sizeof(double),ios_base::beg);
	for (int i=3;i<6;i++)
	{
		double local;
		
		ifile.read(reinterpret_cast<char*>(&local), sizeof(local) );
		oa[i] = local;
		cout << " " << local;
	}
	return 0;
}
