import sqlite3
import random
import time
import threading

#Conecta com o banco
conn = sqlite3.connect('censo.db')
cursor = conn.cursor()

def query1():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, count(*) FROM data GROUP BY pais, sexo;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query2():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, idade, count(*) FROM data GROUP BY pais, sexo, idade;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query3():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, avg(renda) FROM data GROUP BY pais, sexo;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query4():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, avg(idade) FROM data GROUP BY pais, sexo;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query5():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, count(*) FROM data WHERE pais = 15 GROUP BY pais, sexo;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query6():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, count(*) FROM data WHERE pais = 15 AND sexo = 1;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query7():
    count = 0
    timeStart = time.time()
    
    cursor.execute("""
    SELECT pais, sexo, count(*) FROM data WHERE pais >=0 AND pais <=15 GROUP BY pais, sexo;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query8():
    count = 0
    timeStart = time.time()

    #onde estão localizados os bebes mais ricos.
    cursor.execute("""
    SELECT pais, renda, idade FROM data WHERE idade <=4 AND renda > (SELECT avg(renda) from data) GROUP BY idade, pais;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query9():
    count = 0
    timeStart = time.time()

    #quem são os adultos que recebem menos da media salarial
    cursor.execute("""
    SELECT pais, renda, idade FROM data WHERE idade >= 25 AND idade <=50 AND renda < (SELECT avg(renda) from data) GROUP BY idade, pais;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed

def query10():
    count = 0
    timeStart = time.time()

    #onde estao os mais ricos
    cursor.execute("""
    SELECT MAX(renda), pais, count(*) FROM data GROUP BY pais;
    """)
    
    for row in cursor.fetchall():
        #print(row)
        count+=1
    timeElapsed = time.time() - timeStart
    
    print("{} registros retornados em {} segundos.".format(count,timeElapsed))

    return timeElapsed


repeticoes = 3
for i in range(repeticoes):
    query1()
for i in range(repeticoes):
    query2()
for i in range(repeticoes):
    query3()
for i in range(repeticoes):
    query4()
for i in range(repeticoes):
    query5()
for i in range(repeticoes):
    query6()
for i in range(repeticoes):
    query7()
for i in range(repeticoes):
    query8()
for i in range(repeticoes):
    query9()
for i in range(repeticoes):
    query10() #erro


        
        

