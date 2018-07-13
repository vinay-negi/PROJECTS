import requests
import logging
from scraper_project.books.pages.all_books_page import AllBooksPage

logging.basicConfig(format='%(asctime)s %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s',
                    datefmt='%d-%m-%Y %H:%M:%S',
                    level=logging.INFO,
                    filename='log.txt')
logger = logging.getLogger('scraping')

logger.info('Loading books list...')

page_content = requests.get('http://books.toscrape.com/').content
page = AllBooksPage(page_content)

books_list = page.books

for num in range(1, page.page_count):
    url = f'http://books.toscrape.com/catalogue/page-{num+1}.html'
    page_content = requests.get(url).content
    logger.debug('Creating All Books Pages from page content.')
    page = AllBooksPage(page_content)
    books_list.extend(page.books)
