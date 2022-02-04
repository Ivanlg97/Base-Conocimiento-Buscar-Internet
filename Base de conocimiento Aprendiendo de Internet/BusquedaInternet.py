# Librerias de Python utilizadas: 

import requests # Libreria para hacer el requerimiento al servidor
from bs4 import BeautifulSoup # Libreria para obtener arbol de objetos con el codigo HTML de un sitio web
from deep_translator import GoogleTranslator # Libreria para traducir texto (mediante traductor de Google)
from nltk.corpus import stopwords # Libreria para procesamiento del lenguaje natural (incluye las palabras de parada)
from nltk.tokenize import word_tokenize # Libreria para procesamiento del lenguaje natural. Permite tokenizar frases
from statistics import mode # Libreria estadistica

# Codigo del programa:

# Creacion de un objeto de la clase GoogleTranslator

traductor = GoogleTranslator(source='en', target='es') # Permite traducir palabras de inglés a español

# Creacion de encabezados para evitar baneos al hacer un requerimiento al servidor

encabezados = { # Identificacion ante el servidor
    "user-agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko)Chrome/80.0.3987.149 Safari/537.36" # Navegador comun (evita ser baneados)
}

# Funcion eliminar_tildes(string). Permite eliminar las tildes existentes en una cadena (Python distingue caracteres con tilde y sin tilde). Evita coincidencias no deseadas

def eliminar_tildes (cadena) :

    reemplazos = (
        ('á', 'a'),
        ('é', 'e'),
        ('í', 'i'),
        ('ó', 'o'),
        ('ú', 'u')
    )

    for a, b in reemplazos :
        cadena = cadena.replace(a, b).replace(a.upper(), b.upper())

    return cadena

# Funcion buscar_sinonimos(string). Busca sin�nimos de la palabra pasada como argumento

def buscar_sinonimos (palabra):

    # Web scraping en diccionario Word Reference

    url_wordreference = "https://www.wordreference.com/sinonimos/" + palabra # URL semilla para el sitio web del diccionario Word Reference (WR)
    respuesta_wr = requests.get(url_wordreference, headers=encabezados) # Requerimiento al servidor del sitio web de WR

    if (respuesta_wr.status_code == 200): # Comprueba si el servidor ha aceptado el requerimiento

        soup_wr = BeautifulSoup(respuesta_wr.text, features="html.parser") # Arbol de objetos con la estructura HTML del sitio web de WR

        # Obtencion de la lista de sinonimos y antonimos de word reference

        lista_etiquetas = soup_wr.find_all(class_ = "trans clickable") # Busca la clase indicada en el c�digo HTML
        sinonimos_wr = [] # Variable de tipo lista para almacenar los sin�nimos encontrados (incluye tambi�n antonimos de la palabra buscada)

        for etiqueta in lista_etiquetas : 
            lista_sinonimos = etiqueta.find_all('li') # Busca todas las etiquetas <li>. Cada etiqueta ser� un elemento de la lista
            for sinonimo in lista_sinonimos : 
                nuevo_sinonimo = str(sinonimo.text) # Obtenci�n del texto y conversi�n a String
                sinonimos_wr.append(nuevo_sinonimo.lower()) # A�ade a la lista todos los sin�nimos escritos en min�scula

        # Eliminar los antonimos

        for sinonimo in sinonimos_wr :
            if (("antónimos" in sinonimo) == True) : # Comprueba si la palabra 'antónimo' se encuentra en el elemento de la lista
                sinonimos_wr.remove(sinonimo) # La funcion remove elimina el elemento de la lista

        # Separacion de cada elemento de la lista en una cadena 

        sinonimos_wordreference = [] # Variable de tipo lista. Cada elemento corresponde a un sin�nimo de la palabra buscada 

        for sinonimo in sinonimos_wr :
            lista_sinonimos = word_tokenize(sinonimo) # Separa los elementos de la lista existente en palabras
            for sinonimo in lista_sinonimos :
                sinonimo = eliminar_tildes(sinonimo) 
                sinonimos_wordreference.append(sinonimo)

        # Eliminacion de las comas ','

        for sinonimo in sinonimos_wordreference:
            if sinonimo == ',' :
                sinonimos_wordreference.remove(sinonimo)

    else :

        sinonimos_wordreference = []

    # Devolucion de la funcion 

    return sinonimos_wordreference

# Función eliminar_palabras_parada(string)

def eliminar_palabras_parada (palabra) :

    # Tokenizar busqueda 

    lista_buscada = word_tokenize(palabra)

    # Eliminar palabras de parada 

    palabras_parada = set(stopwords.words('spanish'))
    lista_palabras = [] # Variable de tipo lista para almacenar cada palabra buscada como un elemento

    for palabra in lista_buscada :
        if palabra not in palabras_parada :
            lista_palabras.append(palabra)

    # Devolucion de la funcion 

    return lista_palabras

# Función buscar_dato(string1, string2). Busca en Internet (wikidata) el dato relacionado con la palabra pasada como argumento

def buscar_dato(busqueda_realizada, dato_buscado): 

    # Creacion de URL  de wikipedia (URL semilla):

    nombre = busqueda_realizada.title() # Convierte la primera letra de cada palabra en mayusculas 
    nombre = nombre.split() # Convierte la cadena de caracteres en una lista (cada palabra es un elemento de la lista)
    nombre_busqueda = []
    for a in nombre:
        if len(a) < 4 :
            nombre_busqueda.append(a.lower())
        else:
            nombre_busqueda.append(a)
    nombre = "_".join(nombre_busqueda) # Une cada elemento de la lista mediante el caracter '_'
    url_wikipedia = "https://es.wikipedia.org/wiki/" + nombre # Concatenacion de ambas cadenas

    # Requerimiento al servidor del sitio web wikipedia 

    respuesta_wikipedia = requests.get(url_wikipedia, headers=encabezados) # Variable que almacena la estructura HTML del sitio web wikipedia

    # Creacion de la URL de wikidata

    if (respuesta_wikipedia.status_code == 200) : # Comprueba si el servidor ha aceptado el requerimiento

        soup_wikipedia = BeautifulSoup(respuesta_wikipedia.text, features="html.parser") # Arbol de objetos que representa la estructura HTML de wikipedia
        lista_url_wikidata = soup_wikipedia.select('a[href^="https://www.wikidata.org/wiki/Q"]') # Búsqueda de etiqueta por valor de su atributo. Obtiene una lista
        numero_enlaces = len(lista_url_wikidata)
        etiqueta_url_wikidata = lista_url_wikidata[numero_enlaces - 1] # Obtiene el ultimo elemento de la lista
        url_wikidata = etiqueta_url_wikidata.get('href') # Variable en la que se almacena el valor del atributo

        # Requerimiento al servidor del sitio web Wikidata

        respuesta_wikidata = requests.get(url_wikidata, headers=encabezados)

        # Busqueda del dato

        if (respuesta_wikidata.status_code == 200) : 

            soup_wikidata = BeautifulSoup(respuesta_wikidata.text, features="html.parser") 
            contenedor_informacion = soup_wikidata.find('div', class_ = "wikibase-entityview-main").find('div', class_ = "wikibase-statementgrouplistview").find('div', class_ = "wikibase-listview") 
            lista_informacion = contenedor_informacion.find_all('div', class_ = "wikibase-statementgroupview") 
            lista_enunciados = [] # Variable de tipo lista. Almacena el texto de cada posible busqueda (es decir, de cada enunciado)

            for informacion in lista_informacion :
                enunciado = informacion.find('div', class_ = "wikibase-statementgroupview-property").find('div', class_ = "wikibase-statementgroupview-property-label").find('a').text 
                lista_enunciados.append(enunciado)

            # Traduccion de cada enunciado del ingles al español

            lista_enunciados_traducidos = [] # Variable de tipo lista. Cada elemento corresponde a un enunciado traducido

            for enunciado in lista_enunciados: 
                enunciado_traducido = traductor.translate(enunciado)
                nuevo_enunciado = str(enunciado_traducido)
                nuevo_enunciado_minusculas = nuevo_enunciado.lower()
                nuevo_enunciado_sinTildes = eliminar_tildes(nuevo_enunciado_minusculas)
                lista_enunciados_traducidos.append(nuevo_enunciado_sinTildes)

            # Obtencion de sinonimos de la busqueda

            palabras_buscadas = eliminar_palabras_parada(dato_buscado)
            sinonimos = [] # Variable de tipo lista. Almacena todos los sinonimos de cada palabra buscada (con posibles palabras de parada)

            for palabra in palabras_buscadas :
                lista_sinonimos = buscar_sinonimos(palabra)
                for sinonimo in lista_sinonimos :
                    sinonimos.append(sinonimo)

            sinonimos_busqueda = [] # Variable de tipo lista. Almacena todos los sinonimos (sin palabras de parada)

            for sinonimo in sinonimos :
                if sinonimo not in sinonimos_busqueda : # Elimina palabras repetidas
                    if sinonimo not in set(stopwords.words('spanish')) :
                        sinonimos_busqueda.append(sinonimo)

            # Localizacion del enunciado correspondiente al dato buscado

            numero_enunciados = len(lista_enunciados_traducidos) # Numero de elementos en la lista de enunciados traducida (para localizar el indice del enunciado buscado)
            indices = [] # Variable de tipo lista. Almacena los indices de los elementos en los que coincide la busqueda

            if (len(palabras_buscadas) == 1) : # Busqueda de una sola palabra
                for i in range (numero_enunciados) :
                    for palabra in palabras_buscadas :
                        if (lista_enunciados_traducidos[i].find(palabra) != -1) :
                            indices.append(i)
                if (len(indices) == 0) :
                    for j in range (numero_enunciados) :
                        for palabra in sinonimos_busqueda :
                            if (lista_enunciados_traducidos[j].find(palabra) != -1):
                                indices.append(j)

            else : # Busqueda de varias palabras
                for k in range (numero_enunciados) :
                    for palabra in palabras_buscadas :
                        if (lista_enunciados_traducidos[k].find(palabra) != -1) :
                            indices.append(k)
                    for sinonimo in sinonimos_busqueda :
                        if (lista_enunciados_traducidos[k].find(sinonimo) != -1) :
                            indices.append(k)

            # Obtencion del dato correspondiente a la busqueda realizada

            if (len(indices) != 0) : # Comprueba que se ha encontrado el enunciado buscado

                indice = mode(indices) # La funcion mode devuelve el indice mas repetido (mayor numero de coincidencias)
                enunciado_buscado = lista_enunciados[indice]
                etiqueta_enunciado = contenedor_informacion.find('a', string = enunciado_buscado).find_parent('div', class_ = "wikibase-statementgroupview") # localiza el enunciado y asciende el arbol hasta llegar a la etiqueta comun con el dato
                lista_datos = etiqueta_enunciado.find_all('div', class_ = "wikibase-statementview") # Lista de las soluciones al enunciado
                texto_dato_en = '' # Cadena de texto con el dato buscado (en inglés)
                    
                for elemento in lista_datos :
                    dato = elemento.find('div', class_ = "wikibase-snakview-variation-valuesnak")
                    dato = str(dato.text)
                    texto_dato_en += dato + ' '

                # Eliminar expresiones regulares

                lista_expresiones = ['(Spanish)', '(French)', '(Dutch)', '(Gregorian)', '(English)', '(Julian)', '(Russian)', '(Italian)']
                for i in lista_expresiones: 
                    if i in texto_dato_en :
                        texto_dato_en.replace(i, "")

                # Traduccion del dato de ingles a español

                texto_dato_es = traductor.translate(texto_dato_en)
                texto_dato_es = str(texto_dato_es)
                dato_encontrado = eliminar_tildes(texto_dato_es)

            else: 

                dato_encontrado = 'Null'

        else:

            dato_encontrado = 'Null'

    else:

        dato_encontrado = 'Null'

    # Retorno de la funcion: 

    return dato_encontrado