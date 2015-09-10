#ifndef _HEHE_OUTPUT_H_
#define _HEHE_OUTPUT_H_

#include <string>
#include <vector>
#include <sstream>

namespace hehe
{
int OutPut(std::string& file_path, std::string& data);

template <class T>
inline std::string MakeHtmlTable(std::vector<T>& data)
{
	std::ostringstream data_stream;
	data_stream << "<table>";
	long size = data.size();
	for (long i = 0; i < size; i++)
	{
		data[i].ToRow(data_stream);
	}
	data_stream << "</table>";
	return data_stream.str();
}

template <>
inline std::string MakeHtmlTable<int>(std::vector<int>& data)
{
	std::ostringstream data_stream;
	data_stream << "<table>";
	long size = data.size();
	for (long i = 1; i < size; i++)
	{
		data_stream << "<tr><td>"
		<< i
		<< "</td><td>"
		<< data[i]
		<< "<td></tr>";
	}
	data_stream << "</tr></table>";
	return data_stream.str();
}
}


#endif
