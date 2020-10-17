#include "BiTree.h"
#include <assert.h>
#include <stdio.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[])
{
	int i;
	DataType *s;
	DataType ret[13];
	DataType *pre = "abd*f***ce***";//preorder traversal sequence
	DataType *in = "*d*f*b*a*e*c*";//inorder traversal sequence
	DataType *post = "***fd*b**e*ca";//postorder traversal sequence
	BinaryTree T;

	printf("Compile successfully,Congratulation!\n");//If you compile successfully
	s = "*";
	T = CreateBinaryTreeFromPreOrderSequence(&s);
	DestroyTree(&T);
	assert(T == NULL);
	printf("60!\n");//If you create a empty bitree successfully,you will get 60.
	s = pre;
	T = CreateBinaryTreeFromPreOrderSequence(&s);
	s = ret;
	PreOrderTraversal(T, &s);
	for (i = 0; i < 13; ++i) {
		assert(ret[i] == pre[i]);
	}
	printf("70!\n");//If you output perorder traversal result of bitree successfully,you will get 70.
	s = ret;
	InOrderTraversal(T, &s);
	//printf("%s\n", ret);
	for (i = 0; i < 13; ++i) {
		assert(ret[i] == in[i]);
	}
	printf("80!\n");//If you output inorder traversal result of bitree successfully,you will get 80.
	s = ret;
	PostOrderTraversal(T, &s);
	//printf("%s\n", ret);
	for (i = 0; i < 13; ++i) {
		assert(ret[i] == post[i]);
	}
	printf("90!\n");//If you output postorder traversal result of bitree successfully,you will get 90.
	T = DestroyTree(&T);
	assert(T == NULL);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");//If you free all dynamic memory you requested, you will get 100.
	}
	system("PAUSE");
	return 0;
}
