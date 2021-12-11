query = "qualquer coisa" # query para consultar na base de eventos (max. de 300 respostas)
query = urllib.parse.quote(query)

url = 'https://websensors.net.br/minicurso/2019/eventos-br-2017.php?q='+query
headers = {"User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:66.0) Gecko/20100101 Firefox/66.0"}
req = requests.get(url, headers=headers)

pd.set_option('display.max_colwidth', None)
dataset = pd.read_csv(StringIO(req.text),sep='\t', lineterminator='\n')

dataset[['event_id','date','title','local']]
