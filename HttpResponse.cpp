

#include "HttpResponse.h"

HttpResponse::HttpResponse(std::string responseData) {
	_pRawBuffer = new StringBufferHelper(responseData);
	//_responseData = responseData;
	parseHttpResponseData();
		
}

std::string HttpResponse::moveBufferForward(std::string buffer, int newPosition) {
	return buffer.substr(newPosition+1, buffer.size());
}

void HttpResponse::parseHttpResponseData() {
	
	//Get HTTP envelope
	//std::string httpEnvelope = responseData.substr(0, responseData.find("\n"));
	parseHttpEnvelope();
	parseHttpHeaders();
}

void HttpResponse::parseHttpEnvelope() {
	//_httpStatusText = httpEnvelopeData;
	
	//std::string buffer = httpEnvelopeData;
	
	_httpVersion = _pRawBuffer->GetNextSegmentBySeparator(" ");
	_httpStatusCode = _pRawBuffer->GetNextSegmentBySeparator(" ");
	_httpStatusText = _pRawBuffer->GetNextSegmentBySeparator("\n");
}

void HttpResponse::parseHttpHeaders() {
	//_headerMap.ins
	//mymap.insert ( std::pair<char,int>('a',100) );
	
	std::string key, value;
	
	while(true) {
		key = _pRawBuffer->GetNextSegmentBySeparator(": ");
		if(key == "NA")
			break;
		value = _pRawBuffer->GetNextSegmentBySeparator("\n");
		_headerMap.insert ( std::pair<std::string,std::string>(key,value) );
	}
}

std::string HttpResponse::GetHttpVersion() {
	return _httpVersion;
}

std::string HttpResponse::GetHttpStatusCode() {
	return _httpStatusCode;
}

std::string HttpResponse::GetHttpStatusText() {
	return _httpStatusText;
}

std::map<std::string, std::string> HttpResponse::GetHttpHeaders() {
	return _headerMap;
}

std::string HttpResponse::GetRawResponse() {
	return _pRawBuffer->GetRawData();
}