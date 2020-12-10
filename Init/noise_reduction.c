
#include"noise_reduction.h"

void array_swap(int array[], size_t i, size_t j)
{
    int element1 = array[i];
    int element2 = array[j];
    array[i] = element2;
    array[j] = element1;
}

void array_select_sort(int array[], size_t len)
{
    size_t i = 0;
    size_t j;
    int min_index;
    while(i<len)
    {
        /* Find Min Index */
        j= i;
        min_index = j;
        while(j<len)
        {
            if(array[j]<array[min_index])
            {
                min_index = j;
            }
            j+=1;
        }
        array_swap(array,i,min_index);
        i++;
    }
}

void noiseReduction(SDL_Surface *img)
{
  /* Variables */
  int w;
  int h;
  w = img -> w;
  h = img -> h;
  int pixelTable[5];

 for(int i = 0; i < w; i++)
 {
   for(int j = 0; j < h; j++)
   {
     for(int k = j; k <= j + 4; k++)
     {
       //Borders of picture
       if(i == 0)
       {
         if(k == 0)
         {
            pixelTable[0] = get_pixel(img, i, k);
            pixelTable[1] = get_pixel(img, i, k);
            pixelTable[2] = get_pixel(img, i, k);
            pixelTable[3] = get_pixel(img, i, k + 1);
            pixelTable[4] = get_pixel(img, i + 1, k);
            break;
         }
         if(k == h)
         {
            pixelTable[0] = get_pixel(img, i, k);
            pixelTable[1] = get_pixel(img, i, k - 1);
            pixelTable[2] = get_pixel(img, i, k);
            pixelTable[3] = get_pixel(img, i, k);
            pixelTable[4] = get_pixel(img, i + 1, k);
            break;
         }
         else
         {
          pixelTable[0] = get_pixel(img, i, k);
          pixelTable[1] = get_pixel(img, i, k - 1);
          pixelTable[2] = get_pixel(img, i, k);
          pixelTable[3] = get_pixel(img, i, k + 1);
          pixelTable[4] = get_pixel(img, i + 1, k);
          break;
         }
       }
       if(i == w)
       {
          if(k == 0)
          {
            pixelTable[0] = get_pixel(img, i, k);
            pixelTable[1] = get_pixel(img, i, k);
            pixelTable[2] = get_pixel(img, i - 1, k);
            pixelTable[3] = get_pixel(img, i, k + 1);
            pixelTable[4] = get_pixel(img, i, k);
            break;
          }
          if(k == h)
          {
            pixelTable[0] = get_pixel(img, i, k);
            pixelTable[1] = get_pixel(img, i, k - 1);
            pixelTable[2] = get_pixel(img, i - 1, k);
            pixelTable[3] = get_pixel(img, i, k);
            pixelTable[4] = get_pixel(img, i, k);
            break;
          }
          else
          {
            pixelTable[0] = get_pixel(img, i, k);
            pixelTable[1] = get_pixel(img, i, k - 1);
            pixelTable[2] = get_pixel(img, i - 1, k);
            pixelTable[3] = get_pixel(img, i, k + 1);
            pixelTable[4] = get_pixel(img, i, k);
            break;
          }
       }
       if(k == 0)
       {
          pixelTable[0] = get_pixel(img, i, k);
          pixelTable[1] = get_pixel(img, i, k);
          pixelTable[2] = get_pixel(img, i - 1, k);
          pixelTable[3] = get_pixel(img, i, k + 1);
          pixelTable[4] = get_pixel(img, i + 1, k);
          break;
       }
       if(k == h)
       {
        pixelTable[0] = get_pixel(img, i, k);
        pixelTable[1] = get_pixel(img, i, k - 1);
        pixelTable[2] = get_pixel(img, i - 1, k);
        pixelTable[3] = get_pixel(img, i, k);
        pixelTable[4] = get_pixel(img, i + 1, k);
        break;
       }
       else
       {
        pixelTable[0] = get_pixel(img, i, k);
        pixelTable[1] = get_pixel(img, i, k - 1);
        pixelTable[2] = get_pixel(img, i - 1, k);
        pixelTable[3] = get_pixel(img, i, k + 1);
        pixelTable[4] = get_pixel(img, i + 1, k);
        break;
       }
     }
      array_select_sort(pixelTable, 5);
      int med = pixelTable[2];
      put_pixel(img, i, j, med);
   }
 }
}