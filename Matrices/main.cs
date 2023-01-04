using System;
using System.Net.Http.Headers;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace ApiReader
{
    public class ApiReader
    {
        public static async void FetchApi(string url)
        {
            using (HttpClient client = new HttpClient())
            {
                HttpResponseMessage res = await client.GetAsync(url);
                HttpContent content = res.Content;
                string data = await content.ReadAsStringAsync();
                JObject apiData = JObject.Parse(data);
                Console.WriteLine("____________________________________________________");
                foreach (var item in apiData)
                {
                    if (item.Key == "title")
                    {
                        Console.WriteLine($"Title: {item.Value} |");
                    }
                    else if (item.Key == "release_date")
                    {
                        Console.WriteLine($"Release Date : {item.Value} |");
                    }
                    else if (item.Key == "director")
                    {
                        Console.WriteLine($"Director : {item.Value} |");
                    }
                }


            }
        }
        public static void Main(string[] args)
        {
            int NoOfFilms = 6;
            int i = 1;
            while (i <= NoOfFilms)
            {
                string url = @$"https://swapi.dev/api/films/{i++}/";
                FetchApi(url);
            }
            Console.ReadKey();
        }
    }
}