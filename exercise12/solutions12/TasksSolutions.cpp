#include <iostream>

using namespace std;

#define MAX_NAME_SIZE 128
#define MAX_BODY_SIZE 256

struct DateTime
{
	int year, month, day, hour, minute;
};

struct EmailInfo
{
	DateTime sendTime;
	char sender[MAX_NAME_SIZE];
	char recipient[MAX_NAME_SIZE];
	char body[MAX_BODY_SIZE];
};

EmailInfo EnterEmail()
{
	EmailInfo result;
	cin >> result.sendTime.year >> result.sendTime.month >> result.sendTime.day >> result.sendTime.hour >> result.sendTime.minute;
	cin.ignore();//remove the new line
	cin.getline(result.sender, MAX_NAME_SIZE);
	cin.getline(result.recipient, MAX_NAME_SIZE);
	cin.getline(result.body, MAX_BODY_SIZE);

	return result;
}

void EnterEmail(EmailInfo *result)
{
	//(*result).sender <=> result->sender
	cin >> result->sendTime.year >> result->sendTime.month >> result->sendTime.day >> result->sendTime.hour >> result->sendTime.minute;
	cin.ignore();//remove the new line
	cin.getline(result->sender, MAX_NAME_SIZE);
	cin.getline(result->recipient, MAX_NAME_SIZE);
	cin.getline(result->body, MAX_BODY_SIZE);
}

void SwapNames(EmailInfo *src, EmailInfo *dst, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		dst[i] = src[i];

		strcpy(dst[i].sender, src[i].recipient);
		strcpy(dst[i].recipient, src[i].sender);
	}
}

void SwapNamesRecursively(EmailInfo *src, EmailInfo *dst, int size)
{
	if (size == 0)
	{
		return;
	}

	*dst = *src;
	strcpy(dst->sender, src->recipient);
	strcpy(dst->recipient, src->sender);

	SwapNames(src + 1, dst + 1, size - 1);
}

//This is WRONG! Why?! See the next also WRONG function
EmailInfo* SwapNamesWrong(EmailInfo *src, int size)
{
	//100 is the max size
	EmailInfo dst[100];
	for (size_t i = 0; i < size; i++)
	{
		dst[i] = src[i];

		strcpy(dst[i].sender, src[i].recipient);
		strcpy(dst[i].recipient, src[i].sender);
	}

	return dst;
}

//Wrong
int* ReturnArr()
{
	int nums[] = { 1, 2, 3 };

	return nums;
}

void PrintEmail(EmailInfo email)
{
	cout << email.sendTime.year << "." << email.sendTime.month << "." << email.sendTime.day << " " << email.sendTime.hour << ":" << email.sendTime.minute << endl;
	cout << "Sender: " << email.sender << endl;
	cout << "Recipient: " << email.recipient << endl;
	cout << "Body: " << email.body << endl;
}

int main()
{
	EmailInfo emails[3];
	for (size_t i = 0; i < 3; i++)
	{
		EnterEmail(&emails[i]);
	}
	
	EmailInfo dst[3];
	SwapNamesRecursively(emails, dst, 3);
	for (size_t i = 0; i < 3; i++)
	{
		PrintEmail(dst[i]);
	}

	//Test WRONG function
	/*int *nums = ReturnArr();
	for (size_t i = 0; i < 3; i++)
	{
		cout << nums[i] << endl;
	}*/

    return 0;
}

