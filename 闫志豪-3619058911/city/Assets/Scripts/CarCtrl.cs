using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarCtrl : MonoBehaviour
{
    public float speed;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //前进
        if (Input.GetKey(KeyCode.W))
        {
            transform.position += transform.forward * speed * Time.deltaTime;
        }

        //后退
        if (Input.GetKey(KeyCode.S))
        {
            transform.position += -transform.forward * speed * Time.deltaTime;
        }

        //左转
        if (Input.GetKey(KeyCode.A))
        {
            transform.Rotate(-Vector3.up * 50 * Time.deltaTime);
        }

        //右转
        if (Input.GetKey(KeyCode.D))
        {
            transform.Rotate(Vector3.up * 50 * Time.deltaTime);
        }

    }
}
