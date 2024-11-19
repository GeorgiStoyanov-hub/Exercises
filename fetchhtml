/* This is a script that fetches HTML code from HTTP websites
*  It's written using the libcurl library
*  for more information, refer to https://curl.se/
*  This is completely for educational purposes only.
*/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


int main(int argc, char* argv[]) 
{   

    if(argc > 3)
    {
        fprintf(stderr, "\nUsage: %s <URL> <Output>\n", argv[0]);
        fprintf(stderr, "\nError 1 : Too many arguments passed\n");
        return EXIT_FAILURE;
    }
    if(argc != 3)
    {
        fprintf(stderr, "\nUsage: %s <URL> <Output>\n", argv[0]);
        fprintf(stderr, "\nError 2 : Must include 3 arguments\n");
        return EXIT_FAILURE;
    }

    const char* URL = argv[1];
    const char* html_output = argv[2];

    CURL *curl = curl_easy_init();

    if(!curl) 
    {
        fprintf(stderr, "failed to initialize", curl_easy_strerror);
        return EXIT_FAILURE;
    }

    FILE *fl = fopen(html_output, "wb");

    if(!fl)
    {
        perror("Error opening file.");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }


    //setoptions
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    printf("Fetching URL: %s\n", URL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fl);
    printf("Saving to file: %s\n", html_output);
    //perform
    CURLcode result = curl_easy_perform(curl);
    if(result != CURLE_OK)
    {
        fprintf(stderr, "cURL request failed %s\n", curl_easy_strerror(result));
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }
    printf("HTML content successfully saved to '%s'.\n", html_output);
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    printf("HTTP Status Code: %ld\n", http_code);
    if(http_code != 200)
    {
        printf("Request returned HTTP status code %ld.\n", http_code);
    }
    else
    {
        printf("Request was successful!\n");
    }

    curl_easy_cleanup(curl);
    fclose(fl);
    return result == CURLE_OK ? EXIT_SUCCESS : EXIT_FAILURE; 
}
