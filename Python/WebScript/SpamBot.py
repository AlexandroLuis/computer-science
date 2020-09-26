#imports
#-------------------------------------------------------------------------------
import pandas as pd
import schedule
import re
import time
import urllib.request
import os
import requests
from PIL import Image
from io import BytesIO
import json
from time                              import sleep, strftime, gmtime
from selenium                          import webdriver
from selenium.webdriver.support.ui     import WebDriverWait
from selenium.webdriver.support        import expected_conditions as EC
from selenium.webdriver.common.by      import By
from selenium.webdriver.common.keys    import Keys
from selenium.common.exceptions        import TimeoutException
from datetime                          import datetime, timedelta
from selenium.webdriver.chrome.options import Options

#Chromedriver options setup
#-------------------------------------------------------------------------------
options = Options() 
chromeOptions = webdriver.ChromeOptions()
chromeOptions.add_argument("--start-maximized")
chromeOptions.add_experimental_option("useAutomationExtension", False)    
driver = webdriver.Chrome(executable_path=r'PATH/chromedriver.exe',chrome_options=chromeOptions)
options.add_experimental_option('useAutomationExtension',False)
options.add_argument('--ignore-certificate-errors-spki-list')
options.add_argument('--ignore-certificate-errors')#Adicionando argumento para ignorar erro de certificado
options.add_argument('--ignore-ssl-errors')#Adicionando argumento para ignorar erro de ssl  

url = "https://web.whatsapp.com/"
driver.get(url)
WebDriverWait(driver, 5)  

name = 'Vitm'
count = 1 
input('Enter anything after scanning QR code')

user = driver.find_element_by_xpath('//span[@title = "{}"]'.format(name)) 

with open(r'PATH\Train.txt', 'r') as h:
    sub = h.readlines()

re_pattern = r'[0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3} -->'
regex = re.compile(re_pattern)
# Get start times
start_times = list(filter(regex.search, sub))
start_times = [time.split(' ')[0] for time in start_times]
# Get lines
lines = [[]]
for sentence in sub:
    if re.match(re_pattern, sentence):
        lines[-1].pop()
        lines.append([])
    else:
        lines[-1].append(sentence)
lines = lines[1:]

# print(lines)
# df = pd.DataFrame(lines)
df=pd.DataFrame()
for i in lines:
    print(i)
    try:
        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').click()
        time.sleep(2)
        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').send_keys(i)
        time.sleep(2)
        
        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[3]/button').click()
        time.sleep(2)
    except:
        print('')
