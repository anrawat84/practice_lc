#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;
  //char url[]= "http://bulksms.net/API.svc/sms/json/sendmessage";
  char url[]= "http://bulksms.com";
  char postData[] = "username=newuser&password=newpasswd&msg=test&msisdn=9999999999&tagname=Demo&shortcode=8888&telcoId=5&dnRequired=false";
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
//    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  return 0;
}
