import requests
from bs4 import BeautifulSoup

website = 'https://gadgets.ndtv.com/news'
page = requests.get(website)
bsoup = BeautifulSoup(page.content, 'html.parser')

#seperating the headlines
lists = bsoup.findAll(class_='news_listing')

List = []
for i in lists:
	List.append("\n\n🌐")
	List.append(i.text)

#inserting heading for top
List.insert(0,'Tech News')

#list to string
text = " ".join(List)
