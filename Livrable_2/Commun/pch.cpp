// pch.cpp: Quelldatei, die dem vorkompilierten Header entspricht

#include "pch.h"
char* ToStringQuery(System::String^ query) {
	pin_ptr<const wchar_t> wch = PtrToStringChars(query);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((query->Length + 1) * 2);
	errno_t err = 0;
	char* ch = (char*)malloc(sizeInBytes);
	err = wcstombs_s(&convertedChars,
		ch, sizeInBytes,
		wch, sizeInBytes);
	return ch;
}
// Bei der Verwendung vorkompilierter Header ist diese Quelldatei für eine erfolgreiche Kompilierung erforderlich.
