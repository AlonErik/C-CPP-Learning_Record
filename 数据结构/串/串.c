/*	��0�������ַ���ɵ���������, ���ַ���
	ASCII: �ո�: 32	0: 48	A: 65	a: 97

ADT ��(string)
Data
����Ԫ�ؽ���1���ַ����, ����Ԫ�ؾ���ǰ����̵Ĺ�ϵ
Operation
StrAssign(T, *chars): ����1����ֵ�����ַ�������chars�Ĵ�T
StrCopy(T, S): ��S����, �ɴ�S���Ƶô�T
ClearString(S): ��S����, �����
EmptyString(S): ����S����, ����true, ���򷵻�false
StrLength(S): ���ش�S��Ԫ�ظ���
StrCompare(S, T): S>T, ����ֵ>0; S=T, ����0; S<T, ����ֵ<0
Concat(T, S1, S2): ��T������S1��S2���Ӷ��ɵ��´�
SubString(Sub, S, pos, len): ��S����, 1<=pos<=StrLength(S),
							��0<=len<=StrLength(S)-pos+1,
							��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�
Index(S, T, pos): ��S�ʹ�T����, T�ǿ�, 1<=pos<=StrLength(S),
				 ������S�д��ںʹ�T��ͬ���Ӵ�, �򷵻�����S��
				 ��pos���ַ�֮���һ�γ��ֵ�λ��, ���򷵻�0
Replace(S, T, V): ��S, ��T�ʹ�V����, T�ǿ�,
				 ��V�滻����S�г���������T��ȵĲ��ص����Ӵ�
StrInsert(S, pos, T): ��S,�ʹ�T����, 1<=pos<=StrLength(S)+1,
					 �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
StrDelete(S, pos, len): ��S����, 1<=pos<=StrLength(S)-len+1,
					   �ڴ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
*/

