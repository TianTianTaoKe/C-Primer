#include "stdafx.h"

#include "Chapter8.h"

//8.13
int Exercise8_13(int argc, char *argv[])
{
	string line, word;
	vector<PersonInfo> people;
	istringstream is;
	if (argc < 2)
	{
		std::cerr << "请给出文件名" << endl;
		return -1;
	}
	ifstream ifile(argv[1]);
	if (!ifile)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	while (getline(ifile, line))
	{
		PersonInfo person;
		is.clear();
		is.str(line);
		is >> person.name;
		while (is >> word)
		{
			person.phones.push_back(word);
		}
		people.push_back(person);
	}

	ostringstream os;
	for (const auto& entry : people)
	{
		ostringstream formatted, badnum;
		for (const auto& num : entry.phones)
		{
			if (!valid(num))
			{
				badnum << " " << num;
			}
			else
			{
				formatted << " " << format(num);
			}
		}
		if (badnum.str().empty())
		{
			os << entry.name << " "
				<< formatted.str() << endl;
		}
		else
		{
			cerr << "input error :" << entry.name
				<< " invalid number(s)" << badnum.str() << endl;
		}
	}
	cout << os.str() << endl;
	return 0;
}
