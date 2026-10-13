
D1 — Buscar y luego recorrerL:

PROCEDURE FindAndCountActive(sortedIds, isActive, count, targetId)
    first = 0
    last = count - 1
    found = false

    WHILE first <= last AND found is false
        middle = (first + last) / 2

        IF sortedIds[middle] = targetId
            found = true
        ELSE IF sortedIds[middle] < targetId
            first = middle + 1
        ELSE
            last = middle - 1
        END IF
    END WHILE

    activeCount = 0
    FOR index = 0 TO count - 1
        IF isActive[index] is true
            activeCount = activeCount + 1
        END IF
    END FOR

    RETURN found, activeCount
END PROCEDURE

--------------------------------------------------------------

D2 — Revisar conflictos potenciales:

PROCEDURE CountPotentialConflicts(startTimes, count)
    conflictCount = 0

    FOR first = 0 TO count - 1
        second = first + 1

        WHILE second < count
            IF startTimes[first] = startTimes[second]
                conflictCount = conflictCount + 1
            END IF

            second = second + 1
        END WHILE
    END FOR

    RETURN conflictCount
END PROCEDURE


# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode
**Answer:**
La búsqueda binaria crece como O(log n), porque en cada paso descarta
aproximadamente la mitad de los IDs. Después, el ciclo que cuenta las actividades
activas revisa los n elementos, así que crece como O(n). Como las secciones se
ejecutan una después de la otra, sus costos se suman: O(log n) + O(n) = O(n).
No se multiplican porque el recorrido no está dentro del ciclo de búsqueda ni
se repite por cada comparación; el término O(n) domina el crecimiento total.

## D2 — Potential-conflict pseudocode
**Answer:**
`second` comienza en `first + 1` para no comparar una actividad consigo
misma ni revisar dos veces el mismo par en orden inverso. La operación
representativa es comparar `startTimes[first]` con `startTimes[second]`. En el
caso de más trabajo, se revisan todos los pares distintos: hay
`count * (count - 1) / 2` comparaciones, así que el crecimiento es O(count²).
Al duplicar `count`, el número de comparaciones se acerca a cuatro veces el
original (por ejemplo, 4 elementos producen 6 pares y 8 producen 28), no solo
al doble