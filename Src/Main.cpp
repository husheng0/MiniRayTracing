#include "../Head/Commen.h"
#include <thread>
#include <chrono> 
#include <exception>

using namespace mini;

/*
ʹ�÷�����
	ǰ��������������miniRT.exe�볡���ļ�����ͬһ�ļ��У�
	�ڵ�ǰ�ļ��д�CMD��Power Shell���򿪷��������ļ��пհ״���shift+����Ҽ�����Ȼ��ѡ���ڴ˴���CMD��Power Shell����
	��CMD��Power Shell�У����롰./miniRT.exe [Scene�ļ����磺Scene1.rt]��
	Ȼ�������ʾ���뵥���ز�������������ȡ�
*/

//�����������������ϵ�¹���

//������
int main(int argc, char* argv[])
{
	int spp = 1, depth = 1;
#ifndef _DEBUG
	if (argc != 2)
	{
		std::cout << "Can't read scene file, please input scene file as program parameter!\n"
			<< "For Example :\n" << "[in cmd.exe] mimiRT Scene.rt" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		return 0;
	}
	std::cout << "Render parmater:\n"
		<< "Please input SamplePerPixel( Squre number is better):";
	std::cin >> spp;
	std::cout << "Please input TraceDepth:";
	std::cin >> depth;

#endif
	try
	{
		Scene* scene = new Scene(600, 600, spp, depth, color(0, 0, 0));
#ifndef _DEBUG
		scene->initFromFile(argv[1]);
#else
		scene->initFromFile("MyScene.rt");
#endif // !_DEBUG
		scene->renderAndWrite("RayTracing.bmp");
		delete scene;
	}
	catch( std::exception e){
		std::cout << e.what() << std::endl;
	}
	
	system("pause");
	return 0;
}