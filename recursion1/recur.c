/**
 * @file
 * @brief general details of file
 */


/*************************************************************************************************************************************************************/
/*                                                                        INCLUDES                                                                           */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        DEFINES                                                                            */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        DATATYPES                                                                          */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        MACROS                                                                             */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        PRIVATE FUNCTION DECLARATIONS                                                      */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        GLOBAL VARIABLES                                                                   */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        LOCAL VARIABLES                                                                    */
/*************************************************************************************************************************************************************/

/*************************************************************************************************************************************************************/
/*                                                                        FUNCTION DECLARATIONS                                                              */
/*************************************************************************************************************************************************************/


int result=0;
int bitCount(int val) {
   if (val==0) return result;
   if (val==1) return result++;
   if (val>=2)
      {
      val=val-2;
      return result++;
      }   
   bitCount(val);
}
