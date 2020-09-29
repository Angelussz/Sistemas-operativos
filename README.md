# Sistemas-operativos

# Productor
Se creo el struct ya que vamos a crear una memoria limitada, esto ya lo hacemos con shm_open() y mmap() el primera para crear la
memoria que vamos a compartir y lo compartiremos para el productor de manera de lectura y escritura, luego se va a mapear esa
memoria compartida, una vez hecho esto vamos a empezar a crear un for en el cual se esta creando procesos hijos de un solo padre
en estos procesos se debe colocar un sleep() ya que sino aunque el padre se declare un wait(NULL) ellos van a crear otros 
procesos fuera del padre y seran hijos huerfanos o se les asignara otro padre, luego de hacer eso terminamos el producer 
# Consumidor
En esta parte del consumidor se realiza los mismos pasos que el producer solo que en esta ocasion en la parte de shm_open se 
colocara solo de lectura para poder leer el archivo,el mmap() es lo mismo al final se colocara un for() de 3 repeticiones para
poder imprimir cada proceso

# NOTA
No se pudo realizar el laboratorio como describe el informe por falta de conocimientos de mi persona para realizar este mismo
se realizo hasta donde se llego con prueba y error al principio mi productor enviaba datos y los pids al consumidor, ahora solo
manda core dumped se coloco todo a como estaba en un principio cuando siquiera se pudo visualizar los pids en el consumidor pero
sale el mismo error, no se completo laboratorio exitosamente
