import sqlite3
import random
import time
import threading

def generatePeople():
    
    conn = sqlite3.connect('censo.db')
    cursor = conn.cursor()

    timeStart = time.time()
    
    realizado = 0

    #Acrescenta a um vetor de 1000000 posições listas referentes aos registros a serem escritos
    #Após esse laço, escreve no banco. Repete 1000 vezes.
    
    for i in range(1000):

        sqlData = []
        for i in range(1000000):
            sexo = random.randint(0,1)
            idade = random.randint(0,127)
            renda = random.randint(0,1023)*1000
            escolaridade = random.randint(0,3)
            idioma = random.randint(0,4095)
            pais = random.randint(0,255)

            latitude = round(random.uniform(-90,90),3)
            longitude = round(random.uniform(-180,180),3)

            localizador = (latitude,longitude)
            localizador = str(localizador)
            
            data = [sexo,idade,renda,escolaridade,idioma,pais,localizador]
            sqlData.append(data)
            
        cursor.executemany("""
                INSERT INTO data(sexo, idade, renda, escolaridade, idioma, pais, localizador)
                values (?, ?, ?, ?, ?, ?, ?)
                 """,sqlData)
        conn.commit()
        timeEnd = time.time()
        timeElapsed = round(timeEnd-timeStart,2)
        realizado += 1000000
        print("1 milhão de inserções realizadas em {} segundos. Total restante: {}".format(timeElapsed,1000000000-realizado))
        timeStart = time.time()
            
generatePeople()
