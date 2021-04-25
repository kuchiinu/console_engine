#pragma once
#include "Object.h"

//��ʂɕ\�����镶������Ǘ����鎩��\����
typedef struct WordDisplay
{
	const char* word;//������
	int length;//������̒���

	Object object;//�\������I�u�W�F�N�g
};

void WordDisplay_init(WordDisplay* input_WordDisplay, const char* input_word,
	int input_x, int input_y);//������\���̏�����
void WordDisplay_SetWord(WordDisplay* input_WordDisplay, const char* input_word);//������̃Z�b�g
void WordDisplay_SetPosition(WordDisplay* input_WordDisplay, int input_x, int input_y);//������\���̈ړ�
void WordDisplay_SetColor(WordDisplay* input_WordDisplay,
	int font_color, int background_color);//������̐F�̐ݒ�

void WordDisplay_draw(WordDisplay* input_WordDisplay);//������̕`��